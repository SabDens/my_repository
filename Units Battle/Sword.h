#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
private:
public:
	Sword(const char* name, int damage);
	~Sword() = default;
};