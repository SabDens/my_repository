#include "Student.h"
Student::Student(Student& other) 
{
	st_name = other.st_name;
	birthday = other.birthday;
	contact_size = other.contact_size;
	contacts = other.contacts;
	college_information = other.college_information;

	other.clear();
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
	st_name.~My_String();
	birthday.~My_String();
	delete[] contacts;
	contact_size = 0;
	college_information.~My_String();
}
void Student::clear() {
	st_name.clear();
	birthday.clear();
	for (size_t i = 0; i < contact_size; i++)
	{
		contacts[i].clear();
	}
	contact_size = 0;
	college_information.clear();
	
}
Student& Student::operator=(Student& other) {
	st_name = other.st_name;
	birthday = other.birthday;
	college_information = other.college_information;
	contact_size = other.contact_size;
	contacts = other.contacts;
	other.clear();
	return *this;

}