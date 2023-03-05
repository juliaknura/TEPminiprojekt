#include "Main.h"

int main()
{
    geneticAlgorithmTest();

    return 0;
}

void geneticAlgorithmTest()
{
    try
    {
        std::string fileName = "myFile.txt";
        BinaryKnapsackProblem bkp(fileName);
        RandomGenerator gen;

        GeneticAlgorithm ga(POPULATION_SIZE, NUMBER_OF_GENERATIONS, MUTATION_PROBABILITY, CROSSING_OVER_PROBABILITY, &gen, &bkp);
        ga.generate();

        std::cout << CALCULATED_SOLUTION_MSG;
        printVector(ga.getBestSolution());
        std::cout << VALUE_OF_CALCULATED_SOLUTION_MSG;
        std::cout << ga.getBestSolutionValue();

        std::cout << std::endl << std::endl;

        std::cout << OPTIMAL_SOLUTION_MSG;
        std::cout << OPTIMAL_SOLUTION;
        std::cout << VALUE_OF_OPTIMAL_SOLUTION_MSG;
        std::cout << OPTIMAL_VALUE;

        std::cout << std::endl << std::endl;
    }
    catch (InvalidDataException& e) {
        std::cout << ERROR_MSG;
        std::cout << INVALID_DATA_EXCEPTION << e.what();
    }
    catch (FileReadFailException& e) {
        std::cout << ERROR_MSG;
        std::cout << FILE_READ_FAIL_EXCEPTION << e.what();
    }
    catch (FileOpenFailException& e) {
        std::cout << ERROR_MSG;
        std::cout << FILE_OPEN_FAIL_EXCEPTION << e.what();
    }
    catch (std::exception& e)
    {
        std::cout << ERROR_MSG;
        std::cout << UNKNOWN_EXCEPTION << e.what();
    }
    ;
}

void printVector(const std::vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "\t";
    }
    std::cout << std::endl;
}
