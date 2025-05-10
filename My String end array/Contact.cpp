#include "Contact.h"
#include "../My String end array/My_String.h"
Contact::Contact() {
	number = 380730007377;
	city.Init("Odessa");
	country.Init("Ukraine");
}
Contact::Contact(const Contact& other) 
	:number(other.number)
{
	city = other.city;
	country = other.country;
}
Contact::Contact(Contact&& other) 
	:number(other.number)	{
	city = std::move(other.city);
	country = std::move(other.country);
	other.number = 0;
}
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
	
}
void Contact::clear() {
	number = 0;
	city.clear();
	country.clear();
}
Contact& Contact::operator=(const Contact& other) {
	clear();
	number = other.number;
	city = other.city;
	country = other.country;
	return *this;
}

Contact& Contact::operator=(Contact&& other) {
	clear();
	number = other.number;
	other.number = 0;
	city = std::move(other.city);
	country = std::move(other.country);
	return *this;
}
