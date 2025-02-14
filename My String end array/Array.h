#include <iostream>
//https://en.cppreference.com/w/cpp/language/throw

#pragma once
template <typename T>
class Array
{
private:
	T* _data;
	size_t _size;
	size_t _capacity;

public:
	///cоздаёт новый чистый массив
	void NewArr(size_t size);
	///очищает полностью массив
	void Clear();
	///прибавляет к размеру +1 
	void Examination_incr();
	///проверяют и увеличивает невидимую часть массива
	void Examination();
	///увеличивает размер массива
	void NewArrCopy();
	///увеличивает размер массива
	void NewArrCopy(size_t size);
	//конструкторы и деструкторы
	Array();
	Array(size_t size);
	Array(int* data, size_t size);
	Array(Array&& other)noexcept;
	Array(const Array& other);
	~Array();
	///создаёт массив заполненный случайными элементами
	void RandArray(size_t size);
	void RandArray();
	///глубокое копирование
	void Copy(const Array& arr);
	///заполняет часть массива числом
	void ElementX(size_t min, size_t max, T elX);
	/// печатает массив
	void Print() const;
	///вводит размер нынешнего массива
	size_t Size();
	///изменяет размер
	void Size(size_t size);
	///выводит максимальный размер массива
	size_t Capacity();
	///выводит данные по индексу
	T ArrIndex(size_t index);
	///заменяет значение по индексу
	void Element(size_t index, T value);
	///проверяет пустой ли массив
	bool CheckNullptr();
	///заменяет на cлучайный элемент по индексу
	void Rand_to_index(size_t index);
	///увеличивает размер массива
	void ArrSizePlus(size_t size);
	///сортировка массива
	void BoobleSort();
	///выводит минимальное и максимальное число в консоль
	void MinAndMax();
	///добавляет элемент в конец
	void Append(T value);
	/// Видаляє елемент по переданій позиції 
	void Errase(size_t index);
	///Збільшує ємність на визначену величину
	void Reserve(size_t size);
	///Стискає ємність до мінімально можливого розміру
	void Shrink();
	//операторы
	Array& operator=(Array&& other)noexcept;
	Array& operator=(const Array& other);
	Array& operator=(const T* other);
	Array operator+(const Array& other);
	Array& operator+=(const Array& other);
	T operator[](size_t index);
	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const Array<U>& etwas);
	bool operator==(const Array& other);
	bool operator!=(const Array& other);
	bool operator>(const Array& other);
	bool operator<(const Array& other);
	Array operator*(const Array& other);
	///добавляет элемент в начало
	void Fifo_Push(T value);
	///убирает элемент из сначала
	void Fifo_Pop();
	void Lifo_Pop();
};

template <typename T>
void Array<T>::NewArr(size_t size) {
	if (size < 1)
	{
		throw  std::runtime_error("NewArr(size_t size): size < 1");
	}
	Clear();
	_size = size;
	_capacity = _size + 10;
	_data = new T[_capacity];
}

template <typename T>
void Array<T>::Clear() {
	if (!_data)
	{
		return;
	}
	delete[] _data;
	_data = nullptr;
	_size = 0;
	_capacity = 0;
}

template <typename T>
void Array<T>::NewArrCopy()
{
	if (_size < 1)
	{
		throw  std::runtime_error("NewArrCopy(size_t size): size < 1");
	}
	else if (!_data)
	{
		throw  std::runtime_error("NewArrCopy(size_t size): _data == nullptr");
	}

	T* temp_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		temp_data[i] = _data[i];
	}
	_capacity = _size + 10;
	NewArr(_capacity);
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = temp_data[i];
	}

	delete[] temp_data;
}

template <typename T>
void Array<T>::NewArrCopy(size_t size)
{
	if (size<1 )
	{
		throw  std::runtime_error("NewArrCopy(size_t size): size < 1");
	}
	else if (!_data)
	{
		throw  std::runtime_error("NewArrCopy(size_t size): _data == nullptr");
	}


	T* temp_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		temp_data[i] = _data[i];
	}
	_capacity = size + 10;
	NewArr(_capacity);
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = temp_data[i];
	}
	_size = size;
	delete[] temp_data;
}

template <typename T>
void Array<T>::Examination_incr() {
	if (_size >= _capacity)
	{
		NewArrCopy();
		_size++;
	}
	else
	{
		_size++;
	}
}

template <typename T>
void Array<T>::Examination() {
	if (_size >= _capacity)
	{
		NewArrCopy();
	}
}

template <typename T>
Array<T>::Array()
	:_size(), _capacity(10)
{
	_data = new T[_capacity];
}

template <typename T>
Array<T>::Array(size_t size) {
	if (size < 1)
	{
		throw  std::runtime_error("Array(size_t size): size < 1");
	}
	_size = size;
	_capacity = size + 10;
	_data = new T[_capacity];
}

template <typename T>
Array<T>::Array(int* data, size_t size)
{
	if (size < 1 || !data)
	{
		throw  std::runtime_error("Array(int* data, size_t size): size < 1 || !data");
	}
	_size = size;
	_capacity = size + 10;
	_data = new T[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = data[i];
	}

}
template <typename T>
Array<T>::Array(Array&& other) noexcept
{
	if (other._size < 1 || other._data)
	{
		throw  std::runtime_error("Array(Array&& other): other._size < 1 || other._data");
	}
	_size = other._size;
	_capacity = other._capacity;
	_data = other._data;  

	other._data = nullptr;
	other._size = 0;
	other._capacity = 0;

}
template <typename T>
Array<T>::Array(const Array& other)
	:_size(other._size), _capacity(other._capacity)
{
	if (other._size < 1 || other._data)
	{
		throw  std::runtime_error("Array(const Array& other): other._size < 1 || other._data");
	}
	_data = new T[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}
template <typename T>
Array<T>::~Array() {
	delete[] _data;
	_size = 0;
	_capacity = 0;
}

template <typename T>
void Array<T>::RandArray(size_t size) {
	if (size < 1)
		throw  std::runtime_error("RandArray(size_t size): size < 1");
	_size = size;

	NewArr(_size);
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = rand() % 100;
	}
}
template <typename T>
void Array<T>::RandArray() {
	if (_size < 1)
	{
		throw  std::runtime_error("RandArray(): size < 1");
	}
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = rand() % 100;
	}
}

template <typename T>
void Array<T>::Copy(const Array& other) {
	if (!other._data || other._size<1)
	{
		throw  std::runtime_error("Copy(const Array& other): !other._data || other._size<1");
	}
	_size = other._size;
	NewArr(_size);
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}

template <typename T>
void Array<T>::ElementX(size_t min, size_t max, T elX)
{
	if ((min<1 || min >_size)|| (max < 1 || max > _size))
	{
		throw  std::runtime_error("ElementX(size_t min, size_t max, T elX): (min < 1 || min > _size) || (max < 1 || max > _size)");
	}
	if (min > max)
	{
		size_t qwe = min;
		min = max;
		max = qwe;
	}
	if ((min < 0) || (min > _size) || (max < 0) || (max > _size))
	{
		return;
	}
	for (size_t i = min; i < max; i++)
	{
		_data[i] = elX;
	}
}

template <typename T>
void Array<T>::Print() const {
	if (!_data || _size < 1)
		throw  std::runtime_error("Print() const: !_data || _size < 1");

	for (size_t i = 0; i < _size; i++)
	{
		std::cout << _data[i] << " ";
	}
	std::cout << "\n";
}

template <typename T>
size_t Array<T>::Size() {
	return _size;
}

template <typename T>
void Array<T>::Size(size_t size) {
	if (size < 1)
		throw  std::runtime_error("Size(size_t size): size < 1");
	if (size > _size)
	{
		NewArrCopy(size);
	}
	_size = size;
}

template <typename T>
size_t Array<T>::Capacity() {
	return _capacity;
}

template <typename T>
T Array<T>::ArrIndex(size_t index) {
	if (index<0 || index>_size || !_data)
		throw  std::runtime_error("ArrIndex(size_t index): index<0 || index>_size || !_data");
	return _data[index];
}

template <typename T>
void Array<T>::Element(size_t index, T value) {
	if (index<0 || index>_size || !_data)
		throw  std::runtime_error("Element(size_t index, T value): index<0 || index>_size || !_data");
	_data[index] = value;
}

template <typename T>
bool Array<T>::CheckNullptr() {
	if (_data == nullptr)
	{
		return true;
	}
	return false;
}

template <typename T>
void Array<T>::Rand_to_index(size_t index) {
	if (index<0 || index>_size || !_data)
		throw  std::runtime_error("Rand_to_index(size_t index): index<0 || index>_size || !_data");
	_data[index] = rand() % 100;
}
template <typename T>
void Array<T>::ArrSizePlus(size_t size) {
	if (size < 1 || size == _size || !_data)
		throw  std::runtime_error("ArrSizePlus(size_t size): size < 1 || size == _size || !_data");

	T* temp_arr = new T[size];
	if (size > _size)
	{
		for (size_t i = 0; i < _size; i++)
		{
			temp_arr[i] = _data[i];
		}

	}
	if (size < _size)
	{
		for (size_t i = 0; i < size; i++)
		{
			temp_arr[i] = _data[i];
		}
	}
	_size = size;
	Examination();
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = temp_arr[i];
	}

}
template <typename T>
void boobleSort(T* arr, const size_t size)
{
	if (!arr || size < 1)
		throw  std::runtime_error("boobleSort(T* arr, const size_t size): !arr || size < 1");
	T temp;
	bool isSwaped;
	int end = size - 1;
	for (int i = 0; i < size; i++)
	{
		isSwaped = false;
		for (int j = 0; j < end; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSwaped = true;
			}
		}
		if (isSwaped == false)
		{
			return;
		}
		end--;
	}
}

template <typename T>
void Array<T>::BoobleSort() {
	boobleSort(_data, _size);
}

template <typename T>
void Array<T>::MinAndMax() {
	T* temp_arr = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		temp_arr[i] = _data[i];
	}
	boobleSort(temp_arr, _size);
	std::cout << "min" << temp_arr[0] << "\nmax" << temp_arr[_size - 1] << "\n";
	delete[] temp_arr;
}

template <typename T>
void Array<T>::Append(T value) {
	Examination_incr();
	_data[_size] = value;
}

template <typename T>
void Array<T>::Errase(size_t index) {
	if ((index < 0) || (index > _size) || (!_data))
		throw  std::runtime_error("Errase(size_t index): index<0 || index >_size || !_data");
	for (size_t i = index; i < _size -1; i++)
	{
		_data[i] = _data[i + 1];
	}
	_size--;
}
template<typename T>
void Array<T>::Reserve(size_t size) {
	if (size < _size) 
		throw  std::runtime_error("Reserve(size_t size):size < _size");

	T* temp_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		temp_data[i] = _data[i];
	}
	_capacity = size + 10;
	NewArr(_capacity);
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = temp_data[i];
	}

}
template<typename T>
void Array<T>::Shrink() {
	if (_size < 1 || !_data)
		throw  std::runtime_error("Shrink(): _size < 1 || !_data");
	T* temp_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		temp_data[i] = _data[i];
	}
	NewArr(_size-10);
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = temp_data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other)noexcept
{
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator=(Array&& other): other._size < 1 || other.!_data");
	Clear();
	_size = other._size;
	_capacity = other._capacity;
	_data = other._data;
	other._data = nullptr;
	other._size = 0;
	other._capacity = 0;
	return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator=(const Array& other): other._size < 1 || other.!_data");
	Clear();
	_size = other._size;
	_capacity = other._capacity;

	_data = new T[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(const T* other) {
	if (!other)
		throw  std::runtime_error("operator=(const T* other): !other");
	void Clear();
	_size = sizeof(other) / sizeof(other[0]);
	NewArr(_size);
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other[i];
	}
	return *this;
}

template <typename T>
Array<T> Array<T>::operator+(const Array& other) {
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator+(const Array& other): other._size < 1 || other.!_data");
	size_t temp_size = _size;
	size_t temp_size_min = other._size;

	if (_size < other._size) {
		temp_size = other._size;
		temp_size_min = _size;
	}
	T* temp_data = new T[temp_size] {};

	for (size_t i = 0; i < temp_size_min; i++)
	{
		temp_data[i] = _data[i] + other._data[i];
	}
	if (_size > other._size)
	{
		for (size_t i = temp_size_min; i < temp_size; i++)
		{
			temp_data[i] = _data[i];
		}
	}
	else
	{
		for (size_t i = temp_size_min; i < temp_size; i++)
		{
			temp_data[i] = other._data[i];
		}
	}
	Array a(temp_data, temp_size);
	delete[] temp_data;
	return a;
}

template <typename T>
Array<T>& Array<T>::operator+=(const Array& other) {
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator+=(const Array& other): other._size < 1 || other.!_data");
	size_t temp_size = _size;
	size_t temp_size_min = other._size;

	if (_size < other._size) {
		temp_size = other._size;
		temp_size_min = _size;
	}
	int* temp_data = new int[temp_size] {};

	for (size_t i = 0; i < temp_size_min; i++)
	{
		temp_data[i] = _data[i] + other._data[i];
	}
	if (_size > other._size)
	{
		for (size_t i = temp_size_min; i < temp_size; i++)
		{
			temp_data[i] = _data[i];
		}
	}
	else
	{
		for (size_t i = temp_size_min; i < temp_size; i++)
		{
			temp_data[i] = other._data[i];
		}
	}
	delete[] _data;
	_data = temp_data;
	_size = temp_size;
	return *this;
}

template <typename T>
T Array<T>::operator[](size_t index)
{
	if (index<1 || index> _size && !_data)
		throw  std::runtime_error("operator[](size_t index): index<1 && index> _size || !_data");
	return _data[index];
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Array<U>& etwas) {

	for (size_t i = 0; i < etwas._size; i++) {
		os << etwas._data[i] << " ";
	}
	os << "\n";
	return os;
}


template <typename T>
bool Array<T>::operator==(const Array& other)
{
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator==(const Array& other): other._size < 1 || other.!_data");
	if (_size != other._size)
	{
		return false;
	}
	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i] != other._data[i])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
bool Array<T>::operator!=(const Array& other)
{
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator!=(const Array& other): other._size < 1 || other.!_data");
	if (_size != other._size)
	{
		return true;
	}
	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i] != other._data[i])
		{
			return true;
		}
	}
	return false;
}

template <typename T>
bool Array<T>::operator>(const Array& other)
{
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator>(const Array& other): other._size < 1 || other.!_data");
	if (_size > other._size)
	{
		return true;
	}
	return false;
}

template <typename T>
bool Array<T>::operator<(const Array& other)
{
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator<(const Array& other): other._size < 1 || other.!_data");
	if (_size > other._size)
	{
		return false;
	}
	return true;
}

template <typename T>
Array<T> Array<T>::operator*(const Array& other) {
	if (other._size < 1 || !other._data)
		throw  std::runtime_error("operator*(const Array& other): other._size < 1 || other.!_data");
	size_t temp_max_size = _size;
	if (_size < other._size)
	{
		temp_max_size = other._size;
	}

	T* temp_data = new T[_size];
	size_t result_size = 0;

	for (size_t i = 0; i < _size; i++) {
		for (size_t j = 0; j < other._size; j++) {
			if (_data[i] == other._data[j]) {

				temp_data[result_size] = _data[i];
				result_size++;
				break;
			}
		}
	}

	Array a(temp_data, result_size);
	delete[] temp_data;

	return a;
}

template <typename T>
void Array<T>::Fifo_Push(T value) {
	if (_size < 1 || !_data)
		throw  std::runtime_error("Fifo_Push(T value): _size < 1 || !_data");
	Examination_incr();
	for (size_t i = _size-1; i > 0; i--)
	{
		_data[i] = _data[i - 1];
	}
	_data[0] = value;
}

template <typename T>
void Array<T>::Fifo_Pop() {
	if (_size < 2 || !_data)
		throw  std::runtime_error("Fifo_Pop(): _size < 2 || !_data");
	for (size_t i = 0; i < _size-1; i++)
	{
		_data[i] = _data[i + 1];
	}
	_size--;
}

template <typename T>
void Array<T>::Lifo_Pop() {
	if (_size == 0 || !_data)
		throw  std::runtime_error("Lifo_Pop(): _size == 0 || !_data");
	_size--;
}
