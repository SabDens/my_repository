#include <iostream>
#include "Swordsman.h"
#include "Position.h"

Swordsman::Swordsman(const char* name, int power, Sword* sword)
	:Unit(name, 100, sword, Position(0,0)), power(power)
{}

Swordsman::Swordsman(const char* name, int hp, int power, Sword* sword, Position& pos)
	: Unit(name, hp, sword, pos),
	power(power)
{}

void Swordsman::Attack(Unit& enemy) // !!!
{
	if (&enemy == this || enemy.GetHP() == 0 || hp == 0)
	{
		return;
	}
	int damage = weapon->GetDamage() + power * 1.5;
	std::cout << "Swordsman: " << this->name << " Attack " << enemy.GetName() << std::endl;
	enemy.Damaged(damage);
}

void Swordsman::print() const
{
	std::cout << "Swordsman Name:" << name << std::endl;
}
