#pragma once
#include "Array.h"
#include <iostream>


template <typename T>
class Fifo
{
private:
	Array<T> _data;
	size_t _size;
public:
	Fifo();
	void Clear();
	void Pop();
	T Top();
	void Push(T value);
	void Print();
};

template <typename T>
Fifo<T>::Fifo()
	: _size(1)
{
	_data.NewArr(_size);
}

template <typename T>
void Fifo<T>::Clear() {
	_data.Clear();
	_size = 0;
}

template <typename T>
void Fifo<T>::Pop() {
	_data.Fifo_Pop();
	_size = _data.Size();
}

template <typename T>
T Fifo<T>::Top() {
	if (_size == 0) {
		std::cout << "LIFO empty";
	}
	return _data[0];
}

template <typename T>
void Fifo<T>::Push(T value) {
	_data.Fifo_Push(value);
	_size = _data.Size();
}

template <typename T>
void Fifo<T>::Print() {
	std::cout << _data;
}