#pragma once
#include "College.h"

class Student
{
private:
	My_String st_name;
	My_String birthday;
	College* contacts;
	size_t contact_size;
	My_String college_information;
public:
	Student();
	Student(const Student& other);
	Student(Student&& other);
	void Init();
	void Init_Auto(size_t size);
	void Show();
	~Student();
	void clear();
	Student& operator=(const Student& other);
	Student& operator=(Student&& other);
};