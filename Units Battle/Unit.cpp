#define _CRT_SECURE_NO_WARNINGS
#include "Unit.h"
#include <iostream>

Unit::Unit(const char* name, int hp, Weapon* weapon, const Position& pos)
	: hp(hp > 0 ? hp : 100), weapon(weapon), position(pos), range(1)
{
	int len = std::strlen(name) + 1;
	this->name = new char[len];
	std::strcpy(this->name, name);
}

Unit::~Unit()
{
	delete[] name;
}

void Unit::Damaged(int value)
{
	if (hp - value <= 0)
	{
		hp = 0;
		std::cout << this->name << " was killed!" << std::endl; // !!!
	}
	else // hp - value > 0
	{
		hp -= value;
		std::cout << this->name << " wounded on: " << value << " Health: " << hp << std::endl; // !!!
	}
}

int Unit::GetHP() const
{
	return hp;
}

const char* Unit::GetName() const
{
	return name;
}

void Unit::SetPosition(Position& position)
{
	this->position = position;
}

const Position& Unit::GetPosition() const
{
	return position;
}

void Unit::Attack(Unit& enemy) // !!!
{
	if (&enemy == this || enemy.GetHP() == 0 || hp == 0)
	{
		return;
	}
	int damage = weapon->GetDamage();
	std::cout << this->name << " Attack " << enemy.name << std::endl;
	enemy.Damaged(damage);
}

void Unit::print() const
{
	std::cout << "Name:" << name << std::endl;
}
