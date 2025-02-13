#include "../My String end array/My_String.h"
#include <iostream>

void My_String::clear() {
	if (!_string)
	{
		return;
	}
	delete[] _string;
	_string = nullptr;
	_length = 0;
}

My_String::My_String() {
	_length = 80;
	_string = new char[_length];
	_string[0] = '\0';
}

My_String::My_String(size_t length)
{
	if (length < 1) {
		throw  std::runtime_error("My_String(size_t length):length < 1");
	}
	_length=length;
	_string = new char[_length];
}

My_String::My_String(const char* etwas)
{
	if (!etwas) {
		throw  std::runtime_error("My_String(const char* etwas):!etwas");
	}
	_length = strlen(etwas);
	_string = new char[_length + 1];
	for (size_t i = 0; i < _length; i++)
	{
		_string[i] = etwas[i];
	}
	_string[_length] = '\0';
}

My_String::My_String(const My_String& other)
{
	if (!other._string || other._length<1) {
		throw  std::runtime_error("My_String(const My_String& other):!other._string || other._length<1");
	}
	_length=other._length;
	_string = new char[_length + 1];
	for (size_t i = 0; i < _length; i++)
	{
		_string[i] = other._string[i];
	}
	_string[_length] = '\0';
}

My_String::My_String(My_String&& other){
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("My_String(const My_String&& other):!other._string || other._length<1");
	}
	_length = other._length;
	_string = other._string;
	other._string = nullptr;
	other._length = 0;
}
My_String::~My_String()
{
	delete[] _string;
}

void My_String::Print() const
{
	if (!_string || _length < 1) {
		throw  std::runtime_error(" My_String::Print():!_string || _length<1");
	}
	//std::cout << _string << " " << this << "\n";
	std::cout << _string << "\n";
}

void My_String::Init() {
	std::cin.getline(_string, _length);
	_length = strlen(_string);
}

void My_String::Init(const char* new_string) {
	if (!new_string) {
		throw  std::runtime_error("Init(const char* new_string): !new_string");
	}
	size_t  new_length = strlen(new_string);
	clear();
	_string = new char[new_length + 1];
	for (size_t i = 0; i < new_length; i++)
	{
		_string[i] = new_string[i];
	}
	_string[new_length] = '\0';
	_length = new_length;
}


My_String& My_String::operator=(const My_String& other)
{
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("operator=(const My_String& other):!other._string || other._length<1");
	}
	clear();
	_length = other._length;
	_string = new char[_length + 1];

	for (size_t i = 0; i < _length; i++)
	{
		_string[i] = other._string[i];
	}
	_string[_length] = '\0';
	return *this;
}
My_String& My_String::operator=(My_String&& other)
{
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("operator=(const My_String&& other):!other._string || other._length<1");
	}
	clear();
	_string = other._string;
	_length = other._length;
	other._string = nullptr;
	other._length = 0;
	return *this;
}
My_String& My_String::operator=(const char* other) {
	if (!other) {
		throw  std::runtime_error("My_String::operator=(const char* other):!other");
	}
	clear();
	_length = strlen(other);
	_string = new char[_length + 1];
	for (size_t i = 0; i < _length; i++)
	{
		_string[i] = other[i];
	}
	_string[_length] = '\0';
	return *this;
}
My_String My_String::operator+(const My_String& other)
{
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("operator+(const My_String& other):!other._string || other._length<1");
	}
	char* temp_string = new char[_length + other._length + 1];

	for (size_t i = 0; i < _length; i++) {
		temp_string[i] = _string[i];
	}

	for (size_t i = 0; i < other._length; i++) {
		temp_string[_length + i] = other._string[i];
	}
	temp_string[_length + other._length] = '\0';
	My_String result(temp_string);
	return result;
}

My_String& My_String::operator+=(const My_String& other)
{
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("operator+=(const My_String& other):!other._string || other._length<1");
	}
	char* temp_string = new char[_length + other._length + 1];

	for (size_t i = 0; i < _length; i++) {
		temp_string[i] = _string[i];
	}

	for (size_t i = 0; i < other._length; i++) {
		temp_string[_length + i] = other._string[i];
	}
	delete[] _string;
	_string = temp_string;
	_length += other._length;

	return *this;
}

char My_String::operator[](size_t index)
{
	if (index<0|| index>_length) {
		throw  std::runtime_error("operator[](size_t index): index<0|| index>_length");
	}
	return _string[index];
}
std::ostream& operator<<(std::ostream& os, const My_String& etwas) {
	if (!etwas._string || etwas._length<1) {
		throw  std::runtime_error("operator<<: !etwas._string || etwas._length<1");
	}
	os << etwas._string;
	return os;
}
bool My_String::operator==(const My_String& other)
{
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("operator==(const My_String& other): !other._string || other._length < 1");
	}
	if (_length != other._length)
	{
		return false;
	}
	for (size_t i = 0; i < _length; i++)
	{
		if (_string[i] != other._string[i])
		{
			return false;
		}
	}
	return true;
}
bool My_String::operator!=(const My_String& other)
{
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("operator!=(const My_String& other): !other._string || other._length < 1");
	}
	if (_length != other._length)
	{
		return true;
	}
	for (size_t i = 0; i < _length; i++)
	{
		if (_string[i] != other._string[i])
		{
			return true;
		}
	}
	return false;
}
bool My_String::operator>(const My_String& other)
{
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("operator>(const My_String& other): !other._string || other._length < 1");
	}
	if (_length > other._length)
	{
		return true;
	}
	return false;
}

bool My_String::operator<(const My_String& other)
{
	if (!other._string || other._length < 1) {
		throw  std::runtime_error("operator<(const My_String& other): !other._string || other._length < 1");
	}
	if (_length > other._length)
	{
		return false;
	}
	return true;
}
