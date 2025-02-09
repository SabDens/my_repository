#pragma once
#include "../My String end array/My_String.h"
class Contact
{
private:
	size_t number;
	My_String city;
	My_String country;
public:
	Contact();
	Contact(const Contact& other);
	Contact(Contact&& other);
	void Init_Auto();
	//Contact(int a);
	void Init();
	void Show();
	~Contact();
	void clear();
	Contact& operator=(const Contact& other);
	Contact& operator=(Contact&& other);

};
