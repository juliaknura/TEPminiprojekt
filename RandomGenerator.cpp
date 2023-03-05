#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
	:mt(rd()),geneDist(0,1),probDist(0,1) {}

int RandomGenerator::generateRandomGene()
{
	return geneDist(mt);
}

double RandomGenerator::generateRandomProbability()
{
	return probDist(mt);
}

int RandomGenerator::generateRandomPosition(int bound)
{
	return probDist(mt) * bound;
}