#pragma once

#include <bits/bits-stdc++.h>
#include <random>

class RandomGenerator
{
public:
    RandomGenerator();
    int generateRandomGene();
    double generateRandomProbability();
    int generateRandomPosition(int bound);
private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> geneDist;
    std::uniform_real_distribution<double> probDist;
};