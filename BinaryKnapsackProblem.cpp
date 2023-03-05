#include "BinaryKnapsackProblem.h"

BinaryKnapsackProblem::BinaryKnapsackProblem(const std::string& fileName)
	:size(0), noObjects(0) 
{
	readFromFile(fileName);
}

void BinaryKnapsackProblem::readFromFile(const std::string& fileName)
{
	std::fstream file;

	file.open(fileName,std::ios::in);
	if (file.is_open())
	{
		int number = 1;
		int sizeTmp, valueTmp;

		if (!(file >> size)) { file.close(); throw FileReadFailException(number);}
		number++;
		if (!(file >> noObjects)) { file.close(); throw FileReadFailException(number); }
		number++;
		
		for (int i = 0; i < noObjects; i++)
		{
			if (!(file >> sizeTmp)) { file.close(); throw FileReadFailException(number); }
			number++;
			if (!(file >> valueTmp)) { file.close(); throw FileReadFailException(number); }
			number++;
			sizesAndValues.push_back(std::vector<int>{sizeTmp, valueTmp});
		}
		file.close();
		checkIfValid();
	}
	else
	{
		throw FileOpenFailException(FILE_OPEN_ERROR_MSG);
	}

}

void BinaryKnapsackProblem::checkIfValid()
{
	if (size <= 0)
	{
		throw InvalidDataException(INVALID_KNAPSACK_SIZE_MSG);
	}
	if (noObjects <= 0)
	{
		throw InvalidDataException(INVALID_NUMBER_OF_OBJECTS_MSG);
	}
	for (int i = 0; i < noObjects; i++)
	{
		if (sizesAndValues[i][0] <= 0)
		{
			throw InvalidDataException(INVALID_OBJECT_SIZE_MSG);
		}
		if (sizesAndValues[i][1] <= 0)
		{
			throw InvalidDataException(INVALID_OBJECT_VALUE_MSG);
		}
	}
}

BinaryKnapsackProblem::BinaryKnapsackProblem(BinaryKnapsackProblem&& tmp)
	:size(tmp.size), noObjects(tmp.noObjects)
{
	sizesAndValues = std::move(tmp.sizesAndValues);
}
BinaryKnapsackProblem::BinaryKnapsackProblem(const BinaryKnapsackProblem& other)
	:size(other.size), noObjects(other.noObjects)
{
	sizesAndValues = other.sizesAndValues;
}

BinaryKnapsackProblem& BinaryKnapsackProblem::operator=(BinaryKnapsackProblem&& tmp)
{
	size = tmp.size;
	noObjects = tmp.noObjects;
	sizesAndValues = std::move(tmp.sizesAndValues);
	return *this;
}
BinaryKnapsackProblem& BinaryKnapsackProblem::operator=(const BinaryKnapsackProblem& other)
{
	size = other.size;
	noObjects = other.noObjects;
	sizesAndValues = other.sizesAndValues;
	return *this;
}


int BinaryKnapsackProblem::calculateValue(const std::vector<int>& genotype)
{
	int sizeSum = 0, valueSum = 0;
	for (int i = 0; i < noObjects; i++)
	{
		sizeSum += genotype[i] * sizesAndValues[i][0];
		valueSum += genotype[i] * sizesAndValues[i][1];
	}
	if (sizeSum > size)
	{
		return 0;
	}
	else
	{
		return valueSum;
	}
}

int BinaryKnapsackProblem::getNumberOfObjects()
{
	return noObjects;
}
