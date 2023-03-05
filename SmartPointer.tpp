#pragma once
//#include "SmartPointer.h" //DO USUNIECIA

template<typename T>
SmartPointer<T>::SmartPointer<T>(T* newPointer) :pointer(newPointer)
{
	counter = new RefCounter();
	counter->add();
}

template<typename T>
SmartPointer<T>::SmartPointer<T>(const SmartPointer& otherPointer) :pointer(otherPointer.pointer), counter(otherPointer.counter)
{
	counter->add();
}

template<typename T>
SmartPointer<T>::~SmartPointer<T>()
{
	if (counter->dec() == 0)
	{
		delete pointer;
		delete counter;
		//std::cout << deleteMsg;
	}
}

template<typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& other)
{
	if (counter->dec() == 0)
	{
		delete pointer;
		delete counter;
		//std::cout << deleteMsg;
	}
	pointer = other.pointer;
	counter = other.counter;
	counter->add();
	return *this;
}


template<typename T>
T& SmartPointer<T>::operator*()
{
	return *pointer;
}

template<typename T>
T* SmartPointer<T>::operator->() const
{
	return pointer;
}


/////////////////////

template<typename T>
SmartPointer<T[]>::SmartPointer<T[]>(T* newPointer, int newSize) :pointer(newPointer), size(newSize)
{
	counter = new RefCounter();
	counter->add();
}

template<typename T>
SmartPointer<T[]>::SmartPointer<T[]>(const SmartPointer& otherPointer) :pointer(otherPointer.pointer), counter(otherPointer.counter)
{
	counter->add();
}

template<typename T>
SmartPointer<T[]>::~SmartPointer<T[]>()
{
	if (counter->dec() == 0)
	{
		delete[] pointer;
		delete counter;
		//std::cout << deleteMsg2;
	}
}


template<typename T>
SmartPointer<T[]>& SmartPointer<T[]>::operator=(const SmartPointer& other)
{
	if (counter->dec() == 0)
	{
		delete[] pointer;
		delete counter;
		//std::cout << deleteMsg2;
	}
	pointer = other.pointer;
	counter = other.counter;
	counter->add();
}

template<typename T>
T& SmartPointer<T[]>::operator[](int pos)
{
	if (pos < size)
	{
		return pointer[pos];
	}
}

