//#include "Stack.h"
//#include "iostream"
//
//
//Stack::Stack() 
//	: _size(1) 
//{
//	if (_data.CheckNullptr())
//	{
//		_data.NewArr(_size);
//	}
//}
//
//void Stack::Clear() {
//	_data = Array<int>();
//	_size = 0;
//}
//void Stack::Pop() {
//	std::cout << "Pop\n";
//
//	if (_size == 0) {
//		return;
//	}
//	Array<int> temp_data(_size-1);
//	for (size_t i = 0; i < _size-1; i++)
//	{
//		temp_data.Element(i , _data.ArrIndex(i));
//	}
//	_data.Copy(temp_data);
//	_size--;
//}
//int Stack::Top() {
//	
//
//	if (_size==0)
//	{
//		std::cout << "empty\n";
//		return _data.ArrIndex(_size);
//	}
//	return _data.ArrIndex(_size-1);
//}
//void Stack::Push(size_t value) {
//	std::cout << "ArrIndex\n";
//
//	Array temp_data(_size + 1);
//	for (size_t i = 0; i < _size; i++) {
//		temp_data.Element(i, _data.ArrIndex(i));
//	}
//	temp_data.Element(_size, value);
//	_data.Copy(temp_data);
//	_size++;
//}
//void Stack::Print() {
//	
//
//	if (_size == 0) {
//		std::cout << "Print\n";
//		return;
//	}
//	for (size_t i = 0; i < _size; i++) {
//		std::cout << _data.ArrIndex(i) << " ";
//	}
//	std::cout << "\n";
//	
//}