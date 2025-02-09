#include "Student.h"
Student::Student() {
	st_name.Init("Denys Boiko");
	birthday.Init("15.04.2007");
	college_information.Init("It step");
	contact_size = 5;
	contacts = new College[contact_size];
	contacts->Init_Auto(contact_size);

}
Student::Student(const Student& other) 
{
	st_name = other.st_name;
	birthday = other.birthday;
	contact_size = other.contact_size;
	for (size_t i = 0; i < contact_size; i++)
	{
		contacts[i] = other.contacts[i];
	}
	college_information = other.college_information;
}

Student::Student(Student&& other)
{
	st_name = std::move(other.st_name);
	birthday = std::move(other.birthday);
	college_information = std::move(other.college_information);
	contact_size = other.contact_size;
	contacts = other.contacts;
	other.contacts = nullptr;
	other.contact_size = 0;

}

void Student::Init() {
	std::cout << "Student name: ";
	st_name.Init();
	std::cout << "Student birthday: ";
	birthday.Init();
	std::cout << "college information: ";
	college_information.Init();
	std::cout << "contact size: ";
	std::cin >> contact_size;
	contacts = new College[contact_size];
	contacts->Init_arr(contact_size);

}
void Student::Init_Auto(size_t size) {
	st_name.Init("Denys Boiko");
	birthday.Init("15.04.2007");
	college_information.Init("It step");
	contact_size = 5;
	contacts = new College[contact_size];
	(*contacts).Init_Auto(contact_size);
}
void Student::Show() {
	st_name.Print();
	birthday.Print();
	college_information.Print();
	contacts->Show_fur_student();

}
Student::~Student() {
	clear();
}
void Student::clear() {
	st_name.clear();
	birthday.clear();
	college_information.clear();
	delete[] contacts;
	contacts = nullptr;
	contact_size = 0;
	
	
}
Student& Student::operator=(const Student& other) {
	clear();
	st_name = other.st_name;
	birthday = other.birthday;
	college_information = other.college_information;
	contact_size = other.contact_size;

	contacts = new College[contact_size];
	for (size_t i = 0; i < contact_size; i++) {
		contacts[i] = other.contacts[i];
	}
	return *this;

}

Student& Student::operator=(Student&& other) {
	st_name = std::move(other.st_name);
	birthday = std::move(other.birthday);
	college_information = std::move(other.college_information);
	contact_size = other.contact_size;
	contacts = other.contacts;
	other.contacts = nullptr;
	other.contact_size = 0;
	return *this;

}