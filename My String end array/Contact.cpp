#include "Contact.h"
#include "../My String end array/My_String.h"
void Contact::Init_Auto()
{
	number = 380730007377;
	city.Init("Odessa");
	country.Init("Ukraine");
}
void Contact::Init() {
	std::cout << "number: ";
	std::cin >> number;
	std::cin.ignore();

	std::cout << "city: ";
	city.Init();

	std::cout << "country: ";
	country.Init();
}

void Contact::Show() {
	std::cout << "number: " << number << std::endl;
	std::cout << "city: ";
	city.Print();
	std::cout << "country: ";
	country.Print();
}
Contact::~Contact() {
	number = 0;
	city.~My_String();
	country.~My_String();
}
void Contact::clear() {
	number = 0;
	city.clear();
	country.clear();
}

Contact& Contact::operator=(Contact& other) {
	number = other.number;
	city = other.city;
	country = other.country;
	other.number = 0;
	other.clear();
	return *this;
}
