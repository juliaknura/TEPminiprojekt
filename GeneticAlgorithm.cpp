#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int populationSize, int noGenerations, double mutProb, double crossOvProb, RandomGenerator* generator, BinaryKnapsackProblem* bkp)
	:popSize(populationSize), numberOfGenerations(noGenerations),mutationProbability(mutProb),crossingOverProbability(crossOvProb), gen(generator), problem(bkp), bestSolutionValue(0)
{ 
	checkIfDataValid();
}

GeneticAlgorithm::GeneticAlgorithm(GeneticAlgorithm&& tmp)
	:popSize(tmp.popSize), numberOfGenerations(tmp.numberOfGenerations), mutationProbability(tmp.mutationProbability), crossingOverProbability(tmp.crossingOverProbability), gen(tmp.gen), problem(tmp.problem), bestSolutionValue(tmp.bestSolutionValue)
{
	bestSolution = std::move(tmp.bestSolution);
	currentGeneration = std::move(tmp.currentGeneration);
	nextGeneration = std::move(tmp.nextGeneration);
}

GeneticAlgorithm::GeneticAlgorithm(const GeneticAlgorithm& other)
	:popSize(other.popSize), numberOfGenerations(other.numberOfGenerations), mutationProbability(other.mutationProbability), crossingOverProbability(other.crossingOverProbability), gen(other.gen), problem(other.problem), bestSolutionValue(other.bestSolutionValue)
{
	bestSolution = other.bestSolution;
	currentGeneration = other.currentGeneration;
	nextGeneration = other.nextGeneration;
}
GeneticAlgorithm& GeneticAlgorithm::operator=(GeneticAlgorithm&& tmp)
{
	popSize = tmp.popSize;
	numberOfGenerations = tmp.numberOfGenerations;
	mutationProbability = tmp.mutationProbability;
	crossingOverProbability = tmp.crossingOverProbability;
	gen = tmp.gen;
	problem = tmp.problem;
	bestSolutionValue = tmp.bestSolutionValue;
	bestSolution = std::move(tmp.bestSolution);
	currentGeneration = std::move(tmp.currentGeneration);
	nextGeneration = std::move(tmp.nextGeneration);
	return *this;
}
GeneticAlgorithm& GeneticAlgorithm::operator=(const GeneticAlgorithm& other)
{
	popSize = other.popSize;
	numberOfGenerations = other.numberOfGenerations;
	mutationProbability = other.mutationProbability;
	crossingOverProbability = other.crossingOverProbability;
	gen = other.gen;
	problem = other.problem;
	bestSolutionValue = other.bestSolutionValue;
	bestSolution = other.bestSolution;
	currentGeneration = other.currentGeneration;
	nextGeneration = other.nextGeneration;
	return *this;
}


void GeneticAlgorithm::checkIfDataValid()
{
	if (popSize <= 0)
	{
		throw InvalidDataException(INVALID_POPULATION_SIZE_MSG);
	}
	if (numberOfGenerations <= 0)
	{
		throw InvalidDataException(INVALID_NUMBER_OF_GENERATIONS_MSG);
	}
	if (mutationProbability <= 0)
	{
		throw InvalidDataException(INVALID_MUTATION_PROBABILITY_MSG);
	}
	if (crossingOverProbability <= 0)
	{
		throw InvalidDataException(INVALID_CROSSING_OVER_PROBABILITY_MSG);
	}
}

void GeneticAlgorithm::generate()
{
	generateIntialPopulation();

	for (int i = 0; i < numberOfGenerations; i++)
	{
		switchGenerations();
		calculateValues();
		generateNewPopulation();
		mutateNewPopulation();
	}
	switchGenerations();
	calculateValues();
}


void GeneticAlgorithm::generateIntialPopulation()
{
	for (int i = 0; i < popSize; i++)
	{
		nextGeneration.push_back(SmartPointer<Individual>(new Individual(problem->getNumberOfObjects(),gen)));
	}
}

void GeneticAlgorithm::mutateNewPopulation()
{
	for (int i = 0; i < popSize; i++)
	{
		nextGeneration[i]->mutate(mutationProbability);
	}
}

void GeneticAlgorithm::calculateValues()
{
	for (int i = 0; i < popSize; i++)
	{
		if (currentGeneration[i]->getValue() == invalidValue)
		{
			currentGeneration[i]->calculateValue(problem);
		}
		if (currentGeneration[i]->getValue() > bestSolutionValue)
		{
			bestSolutionValue = currentGeneration[i]->getValue();
			bestSolution = currentGeneration[i]->getGenotype();
		}
	}
}

void GeneticAlgorithm::generateNewPopulation()
{
	int randomNumber1, randomNumber2;
	SmartPointer<Individual>parent1(currentGeneration[0]), parent2(currentGeneration[0]);
	
	//if uneven population size
	if (popSize % 2 == 1)
	{
		randomNumber1 = gen->generateRandomPosition(popSize-1);
		nextGeneration.push_back(currentGeneration[randomNumber1]);
	}

	for (int i = popSize % 2; i < popSize; i+=2)
	{
		//picking parents
		randomNumber1 = gen->generateRandomPosition(popSize - 1);
		randomNumber2 = gen->generateRandomPosition(popSize - 1);
		if (currentGeneration[randomNumber1]->getValue() > currentGeneration[randomNumber2]->getValue())
		{
			parent1 = currentGeneration[randomNumber1];
		}
		else
		{
			parent1 = currentGeneration[randomNumber2];
		}
		randomNumber1 = gen->generateRandomPosition(popSize - 1);
		randomNumber2 = gen->generateRandomPosition(popSize - 1);
		if (currentGeneration[randomNumber1]->getValue() > currentGeneration[randomNumber2]->getValue())
		{
			parent2 = currentGeneration[randomNumber1];
		}
		else
		{
			parent2 = currentGeneration[randomNumber2];
		}

		//creating offspring
		if (gen->generateRandomProbability() < crossingOverProbability)
		{
			std::pair<Individual*, Individual*> pair = parent1->createOffspring(parent2);

			nextGeneration.push_back(SmartPointer<Individual>(pair.first));
			nextGeneration.push_back(SmartPointer<Individual>(pair.second));
		}
		else
		{
			nextGeneration.push_back(parent1);
			nextGeneration.push_back(parent2);
		}
		
	}
}

void GeneticAlgorithm::switchGenerations()
{
	currentGeneration = nextGeneration;
	nextGeneration.clear();
}

std::vector<int> GeneticAlgorithm::getBestSolution()
{
	return bestSolution;
}

int GeneticAlgorithm::getBestSolutionValue()
{
	return bestSolutionValue;
}
