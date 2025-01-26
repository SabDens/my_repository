#pragma once
#include "../My String end array/My_String.h"

enum Grade
{
	Common=1,
	Rare=2,
	Epic=3,
	Legendary=4,
	Mythic=5
};


class Weapon
{
protected:
	My_String name;

	Grade grade;
	unsigned int damage;
public:
	Weapon(Grade grade_, const char* name_);
	Weapon(const char* name_);
	~Weapon();
	unsigned int GetDamege();
	virtual void UpGrade();
	Grade GetGrade();
};

class Sword : public Weapon
{
	
public:
	Sword()
		:Weapon(Common,"Sworderson")
	{
		damage += 30;
	}
	unsigned int GetDamage();
	void UpGrade()override;
};
//
//
class Stick : public Weapon
{
private:

	unsigned int charges;

public:
	Stick()
		:Weapon(Common, "Sworderson"), charges(40)
	{
		damage += 30;
	}
	unsigned int GetDamage();
	void UpGrade()override;
};


class Bow : public Weapon
{
private:
	unsigned int max_damage;


public:
	Bow()
		:Weapon(Common, "Sworderson")
	{
		damage += 30;
	}
	unsigned int GetDamage();
	void UpGrade()override;
};