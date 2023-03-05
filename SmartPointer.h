#pragma once
#include "RefCounter.h"
#include <string>

const std::string deleteMsg = "delete\n";
const std::string deleteMsg2 = "delete[]\n";

template<typename T>
class SmartPointer
{
public:
	SmartPointer(T* newPointer);
	~SmartPointer();
	SmartPointer(const SmartPointer& other);

	SmartPointer& operator=(const SmartPointer& other);
	T& operator*();
	T* operator->() const;
private:
	T* pointer;
	RefCounter* counter;

};

template<typename T>
class SmartPointer<T[]>
{
public:
	SmartPointer(T* newPointer, int newSize);
	~SmartPointer();
	SmartPointer(const SmartPointer& other);

	SmartPointer& operator=(const SmartPointer& other);
	T& operator[](int pos);
private:
	T* pointer;
	RefCounter* counter;
	int size;

};


#include "SmartPointer.tpp"