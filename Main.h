#pragma once
#include "BinaryKnapsackProblem.h"
#include "Individual.h"
#include "SmartPointer.h"
#include "GeneticAlgorithm.h"

const std::string ERROR_MSG = "Oops... it seems like something went wrong\n";
const int POPULATION_SIZE = 21;
const int NUMBER_OF_GENERATIONS = 40;
const double MUTATION_PROBABILITY = 0.1;
const double CROSSING_OVER_PROBABILITY = 0.7;

const std::string CALCULATED_SOLUTION_MSG = "The solution calculated by the genetic algorithm:\n";
const std::string VALUE_OF_CALCULATED_SOLUTION_MSG = "Value of the calculated solution is: ";

const std::string OPTIMAL_SOLUTION_MSG = "Optimal solution:\n";
const std::string VALUE_OF_OPTIMAL_SOLUTION_MSG = "Value of the optimal solution is: ";

const std::string OPTIMAL_SOLUTION = "0       1       1       0       1       0       0       0       0       0\n";
const int OPTIMAL_VALUE = 105;


const std::string INVALID_DATA_EXCEPTION = "InvalidDataException: ";
const std::string FILE_READ_FAIL_EXCEPTION = "FileReadFailException: ";
const std::string FILE_OPEN_FAIL_EXCEPTION = "FileOpenFailException: ";
const std::string UNKNOWN_EXCEPTION = "Unknown exception: ";

void printVector(const std::vector<int>& v);
void geneticAlgorithmTest();
