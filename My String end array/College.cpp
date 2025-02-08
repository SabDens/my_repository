#include "College.h"

void College::Init(size_t size) {
	std::cout << "college name: ";
	name.Init();
	_size = size;
	contacts = new Contact[_size];

	for (size_t i = 0; i < _size; i++)
	{
		//contacts[i].Init_Auto();
		contacts[i].Init();
	}
}
void College::Init_Auto(size_t size) {
	name.Init("It Step");
	_size = size;
	contacts = new Contact[_size];

	for (size_t i = 0; i < _size; i++)
	{
		contacts[i].Init_Auto();
	}
}
void College::Init_arr(size_t size) {

	_size = size;
	contacts = new Contact[_size];

	for (size_t i = 0; i < _size; i++)
	{
		contacts[i].Init();
	}
}


void College::Show() {
	std::cout << "college name: ";
	name.Print();
	for (size_t i = 0; i < _size; i++)
	{
		contacts[i].Show();
	}
}
void College::Show_fur_student() {
	for (size_t i = 0; i < _size; i++)
	{
		contacts[i].Show();
	}
}
College::~College() {
	delete[] contacts;
	_size = 0;
	name.~My_String();
}
void College::clear() {
	for (size_t i = 0; i < _size; i++)
	{
		contacts[i].clear();
	}
	contacts = nullptr;
	_size = 0;
	name.clear();
}
College& College::operator=( College& other) {

	_size = other._size;
	name = other.name;
	for (size_t i = 0; i < _size; i++)
	{
		contacts[i] = other.contacts[i];
	}
	other.clear();
	return *this;

}
