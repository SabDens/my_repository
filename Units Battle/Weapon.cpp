#include "Weapon.h"

Weapon::Weapon(Grade grade_, const char* name_)
	:damage(30), grade(grade_), name(name_)
{
}
Weapon::Weapon(const char* name_)
	:damage(30), grade(Common), name(name_)
{
}
Weapon::~Weapon() {

}
unsigned int Weapon::GetDamege() {
	return damage * grade;
}


void Weapon::UpGrade() {

	switch (grade) {
	case 1:
		grade = Grade::Rare;
		std::cout << "improvement to Rare";
		damage += 5;
		break;
	case 2:
		grade = Grade::Epic;
		std::cout << "improvement to Epic";
		damage += 15;
		break;
	case 3:
		grade = Grade::Legendary;
		std::cout << "improvement to Legendary";
		damage += 25;
		break;
	case 4:
		grade = Grade::Mythic;
		std::cout << "improvement to Mythic";
		damage += 35;
		break;
	default:
		std::cout << "maximum rarity";
		damage += 5;
	}


}
Grade Weapon::GetGrade() {
	return grade;
}

//Sword

unsigned int Sword::GetDamage() {

	return damage * grade + 10;
}


void Sword::UpGrade() {
	Weapon::UpGrade();
}


//Stick

unsigned int Stick::GetDamage() {
	if (charges>2)
	{
		return damage * grade;
	}
	else
	{
		charges += 4;
		return 0;
	}

}


void Stick::UpGrade() {
	Weapon::UpGrade();
}

//Bow

unsigned int Bow::GetDamage() {

	return damage / 2 * grade + 20;
}


void Bow::UpGrade() {
	Weapon::UpGrade();
}