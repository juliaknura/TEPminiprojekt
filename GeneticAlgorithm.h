#pragma once
#include "BinaryKnapsackProblem.h"
#include "Individual.h"
#include "SmartPointer.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm() = delete;
	GeneticAlgorithm(int populationSize, int noGenerations, double mutProb, double crossOvProb, RandomGenerator* generator, BinaryKnapsackProblem* bkp);

	GeneticAlgorithm(GeneticAlgorithm&& tmp);
	GeneticAlgorithm(const GeneticAlgorithm& other);
	GeneticAlgorithm& operator=(GeneticAlgorithm&& tmp);
	GeneticAlgorithm& operator=(const GeneticAlgorithm& other);
	
	void generate();
	std::vector<int> getBestSolution();
	int getBestSolutionValue();
private:
	void checkIfDataValid();
	void generateIntialPopulation();
	void mutateNewPopulation();
	void calculateValues();
	void generateNewPopulation();
	void switchGenerations();
	int popSize, numberOfGenerations;
	RandomGenerator* gen;
	double mutationProbability, crossingOverProbability;
	std::vector<int> bestSolution;
	int bestSolutionValue;
	std::vector<SmartPointer<Individual>> currentGeneration, nextGeneration;
	BinaryKnapsackProblem* problem;
};
