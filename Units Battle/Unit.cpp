#include "Unit.h"
// Unit

Unit::Unit(const char* name_, int hp)
	:HP(hp), Weapon(Common, name_), speed(10), name(name_)
{

}
Unit::Unit(int hp)
	:HP(hp), Weapon(Common, ""), speed(10), name("Denys")
{
}

Unit::Unit(const char* name_)
	:HP(1000), Weapon(Common, name_), speed(10), name(name_)
{

}
Unit::~Unit() {

}
void Unit::TakeDamage(int value) {
	if (IslnDefense)
	{
		HP -= value/2;
		return;
	}
	
	HP -= value;
}
void Unit::Atack(Unit& enemy) {
	std::cout << "Unit " << name << " Attack" << enemy.name << std::endl;
	
	enemy.HP -= GetDamege();
}
void Unit::Defense() {
	if (IslnDefense)
	{
		IslnDefense = false;
		return;
	}
	IslnDefense = true;
}

void Unit::Print() const {
	std::cout << "Unit:\n" << "Name " << name << "\n" << "HP " << HP << "\n" << "speed " << speed << "\n" << "Weapon: \n";
	std::cout << "Name " << name << "\n" << "Grade " <<grade << "\n" << "min damage " << damage / 2;
}

//Swordman



Swordman::~Swordman()
{
}
void Swordman::Atack(Unit& enemy)
{
	Unit::Atack(enemy);
}
void Swordman::Defense()
{
	Unit::Defense();
}
void Swordman::TakeDamage(int value) {
	if (IslnDefense)
	{
		HP -= value / 2;
		return;
	}

	HP -= value;
}

// Archer

Archer::~Archer()
{
}
void Archer::Atack(Unit& enemy)
{
	if (arrows>3)
	{
		Unit::Atack(enemy);
		Unit::Atack(enemy);
		Unit::Atack(enemy);
	}
	else
	{
		arrows += 5;
	}
}
void Archer::Defense()
{
	Unit::Defense();
}
void Archer::TakeDamage(int value) {
	if (IslnDefense)
	{
		HP -= value / 2;
		return;
	}

	HP -= value;
}

//Mage



Mage::~Mage()
{
}
void Mage::Atack(Unit& enemy)
{
	if (mana > 10)
	{
		Unit::Atack(enemy);
		Unit::Atack(enemy);
	}
	else
	{
		mana += 15;
	}
}
void Mage::Defense()
{
	Unit::Defense();
}
void Mage::TakeDamage(int value) {
	if (IslnDefense)
	{
		HP -= value / 2;
		return;
	}

	HP -= value;
}