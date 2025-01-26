//#pragma once
//#include "Array.h"
//#include <iostream>
//
//
//template <typename T>
//class Stack
//{
//private:
//	Array<T> _data;
//	size_t _size;
//public:
//	Stack();
//	void Clear();
//	void Pop();
//	int Top();
//	void Push(T value);
//	void Print();
//};
//
//
//template <typename T>
//Stack<T>::Stack()
//	: _size(1)
//{
//	if (_data.CheckNullptr())
//	{
//		_data.NewArr(_size);
//	}
//}
//
//template <typename T>
//void Stack<T>::Clear() {	
//	_data.Clear();
//	_size = 0;
//}
//
//template <typename T>
//void Stack<T>::Pop() {
//	if (_size == 0) {
//		std::cout << "stack empty";
//	}
//	_size--;
//}
//
//template <typename T>
//int Stack<T>::Top() {
//	if (_size == 0) {
//		std::cout << "stack empty";
//		return;
//	}
//	return _data.ArrIndex(_size - 1);
//}
//
//template <typename T>
//void Stack<T>::Push(T value) {
//	_data.Append(value);
//	_size++;
//}
//
//template <typename T>
//void Stack<T>::Print() {
//	for (size_t i = 0; i < _size; i++) {
//		std::cout << _data.ArrIndex(i) << " ";
//	}
//	std::cout << "\n";
//
//}