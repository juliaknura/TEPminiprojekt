#include "Individual.h"


Individual::Individual(int size, RandomGenerator* gen)
	:value(0), valueCalculated(false), gen(gen)
{
	int randomNumber;

	for (int i = 0; i < size; i++)
	{
		randomNumber = gen->generateRandomGene();
		genotype.push_back(randomNumber);
	}
}

Individual::Individual(const std::vector<int>& gtype, RandomGenerator* gen)
	:value(0), valueCalculated(false), gen(gen)
{
	genotype = gtype;
}

Individual::Individual(const Individual& other)
{
	value = other.value;
	valueCalculated = other.valueCalculated;
	gen = other.gen;
	genotype = other.genotype;
}

Individual::Individual(Individual&& tmp)
{
	value = tmp.value;
	valueCalculated = tmp.valueCalculated;
	gen = tmp.gen;
	genotype = std::move(tmp.genotype);
}

Individual& Individual::operator=(const Individual& other)
{
	value = other.value;
	valueCalculated = other.valueCalculated;
	gen = other.gen;
	genotype = other.genotype;
	return *this;
}

Individual& Individual::operator=(Individual&& tmp)
{
	value = tmp.value;
	valueCalculated = tmp.valueCalculated;
	gen = tmp.gen;
	genotype = std::move(tmp.genotype);
	return *this;
}

int Individual::calculateValue(BinaryKnapsackProblem* bkp)
{
	value = bkp->calculateValue(genotype);
	valueCalculated = true;
	return value;
}

int Individual::getValue()
{
	if (valueCalculated) return value;
	else return invalidValue;
}

void Individual::mutate(double mutationProbability)
{
	double randomNumber;
	for (int i = 0; i < genotype.size(); i++)
	{
		randomNumber = gen->generateRandomProbability();
		if (randomNumber < mutationProbability)
		{
			genotype[i] = (genotype[i] + 1) % 2;
			valueCalculated = false;
		}
	}
}

std::pair<Individual*, Individual*> Individual::createOffspring(const SmartPointer<Individual> other) const
{
	int randomNumber = 1+gen->generateRandomPosition(genotype.size() - 2);
	std::vector<int> child1gene, child2gene;
	for (int i = 0; i < randomNumber; i++)
	{
		child1gene.push_back(genotype[i]);
		child2gene.push_back(other->genotype[i]);
	}
	for (int i = randomNumber; i < genotype.size(); i++)
	{
		child2gene.push_back(genotype[i]);
		child1gene.push_back(other->genotype[i]);
	}

	Individual* child1 = new Individual(child1gene,gen);
	Individual* child2 = new Individual(child2gene,gen);
	return std::pair<Individual*, Individual*>(child1,child2);
}

std::vector<int> Individual::getGenotype()
{
	return genotype;
}