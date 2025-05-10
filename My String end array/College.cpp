#include "College.h"
College::College() {
	name.Init("It Step");
	_size = 10;
	contacts = new Contact[_size];
	for (size_t i = 0; i < _size; i++)
	{
		contacts[i].Init_Auto();
	}
}
College::College(const College& other) {
	_size = other._size;
	name = other.name;
	contacts = new Contact[_size];

	for (size_t i = 0; i < _size; i++)
	{
		contacts[i] = other.contacts[i];
	}

}
College::College(College&& other) {
	_size = other._size;
	name = std::move(other.name);

	contacts = other.contacts;
	other.contacts = nullptr;
	other._size = 0;

}
void College::Init(size_t size) {
	clear();
	std::cout << "college name: ";
	name.Init();
	_size = size;
	contacts = new Contact[_size];

	for (size_t i = 0; i < _size; i++)
	{
		contacts[i].Init();
	}
}
void College::Init_Auto(size_t size) {
	clear();
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
}
void College::clear() {
	delete[] contacts;
	contacts = nullptr;
	_size = 0;
	name.clear();
}
College& College::operator=(const College& other) {
	clear();
	_size = other._size;
	name = other.name;
	contacts = new Contact[_size];

	for (size_t i = 0; i < _size; i++)
	{
		contacts[i] = other.contacts[i];
	}

	return *this;
}

College& College::operator=(College&& other) {
	clear();
	_size = other._size;
	name = std::move(other.name);

	contacts = other.contacts;
	other.contacts = nullptr;
	other._size = 0;

	return *this;
}

