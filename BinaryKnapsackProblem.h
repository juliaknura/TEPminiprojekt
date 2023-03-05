#pragma once
#include <bits/bits-stdc++.h>
#include "Exceptions.h"

const std::string FILE_OPEN_ERROR_MSG = "Failed to open file\n";
const std::string INVALID_DATA_MSG = "Data cannot be negative or equal to zero\n";
const std::string INVALID_KNAPSACK_SIZE_MSG = "Knapsack size cannot be negative or equal to zero\n";
const std::string INVALID_NUMBER_OF_OBJECTS_MSG = "Number of objects cannot be negative or equal to zero\n";
const std::string INVALID_OBJECT_SIZE_MSG = "Object size cannot be negative or equal to zero\n";
const std::string INVALID_OBJECT_VALUE_MSG = "Obejct value cannot be negative or equal to zero\n";
const std::string INVALID_POPULATION_SIZE_MSG = "Population size cannot be negative or equal to zero\n";
const std::string INVALID_NUMBER_OF_GENERATIONS_MSG = "Number of generations cannot be negative or equal to zero\n";
const std::string INVALID_MUTATION_PROBABILITY_MSG = "Mutation probability cannot be negative or equal to zero\n";
const std::string INVALID_CROSSING_OVER_PROBABILITY_MSG = "Crossing-over probability cannot be negative or equal to zero\n";

class BinaryKnapsackProblem
{
public:
	BinaryKnapsackProblem() = delete;
	BinaryKnapsackProblem(const std::string& fileName);
	BinaryKnapsackProblem(BinaryKnapsackProblem&& tmp);
	BinaryKnapsackProblem(const BinaryKnapsackProblem& other);

	BinaryKnapsackProblem& operator=(BinaryKnapsackProblem&& tmp);
	BinaryKnapsackProblem& operator=(const BinaryKnapsackProblem& other);

	void readFromFile(const std::string& fileName);
	int calculateValue(const std::vector<int>& genotype);
	int getNumberOfObjects();

private:
	void checkIfValid();
	int size, noObjects;
	std::vector< std::vector<int> > sizesAndValues;

};
