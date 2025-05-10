#define _CRT_SECURE_NO_WARNINGS
#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const char* name, int damage)
	: damage(damage > 0 ? damage : 5)
{
	int len = std::strlen(name) + 1;
	this->name = new char[len];
	std::strcpy(this->name, name);
}

Weapon::~Weapon()
{
	delete[] name;
}

int Weapon::GetDamage() const
{
	return damage;
}