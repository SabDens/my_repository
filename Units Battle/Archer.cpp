#include "Archer.h"
#include <iostream>

Archer::Archer(const char* name, int hp, int arrows, Bow* bow)
	: Unit(name, hp, bow, Position(0,0)),
	arrows(arrows > 0 ? arrows : 60)
{
}

Archer::Archer(const char* name, int hp, int arrows, Bow* bow, Position& pos)
	: Unit(name, hp, bow, pos),
	arrows(arrows > 0 ? arrows : 60)
{}

void Archer::Attack(Unit& enemy) // !!!
{
	if (&enemy == this || enemy.GetHP() == 0 || hp == 0)
	{
		return;
	}
	int damage = weapon->GetDamage();
	arrows -= 1;
	std::cout << "Archer: " << this->name << " Attack " << enemy.GetName() << " Arrows: " << arrows << std::endl;
	enemy.Damaged(damage);
}

void Archer::print() const
{
	std::cout << "Archer: " << name << " Arrows: " << arrows << std::endl;
}
