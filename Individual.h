#pragma once
#include <bits/bits-stdc++.h>
#include <random>
#include "BinaryKnapsackProblem.h"
#include "RandomGenerator.h"
#include "SmartPointer.h"


const int range = 100;
const int invalidValue = -1;

class Individual
{
public:
	Individual() = delete;
	Individual(const std::vector<int>& gtype, RandomGenerator* gen);
	Individual(const Individual& other);
	Individual(Individual&& temp); 
	Individual(int size, RandomGenerator* gen);

	Individual& operator=(const Individual& other);
	Individual& operator=(Individual&& temp);

	int calculateValue(BinaryKnapsackProblem* bkp);
	int getValue();
	void mutate(double mutationProbability);
	std::pair<Individual*,Individual*> createOffspring(const SmartPointer<Individual> other) const;
	std::vector<int> getGenotype();

private:
	std::vector<int> genotype;
	int value;
	bool valueCalculated;
	RandomGenerator* gen;
};