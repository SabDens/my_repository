#pragma once
#include "Array.h"
#include <iostream>


template <typename T>
class Lifo
{
private:
	Array<T> _data;
	size_t _size;
public:
	Lifo();
	void Clear();
	void Pop();
	T Top();
	void Push(T value);
	void Print();
};

template <typename T>
Lifo<T>::Lifo()
{
	_size=0;
	_data.Size(_size);
}

template <typename T>
void Lifo<T>::Clear() {
	_data.Clear();
	_size = 0;
}

template <typename T>
void Lifo<T>::Pop() {
	if (_size == 0) {
		std::cout << "LIFO empty";
	}
	_data.Lifo_Pop();
}

template <typename T>
T Lifo<T>::Top() {
	if (_size == 0) {
		std::cout << "LIFO empty";
	}
	return _data.ArrIndex(_size - 1);
}

template <typename T>
void Lifo<T>::Push(T value) {
	_data.Examination_incr(); 
	_data.Element(_size, value);
	_size++;
}


template <typename T>
void Lifo<T>::Print() {
	std::cout << _data;

}