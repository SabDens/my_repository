#pragma once
#include "../My String end array/My_String.h"
class Contact
{
private:
	size_t number;
	My_String city;
	My_String country;
public:
	void Init_Auto();
	//Contact(int a);
	void Init();
	void Show();
	~Contact();
	void clear();
	Contact& operator=(Contact& other);

};
