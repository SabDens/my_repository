#pragma once
#include "../My String end array/My_String.h"
#include "Weapon.h"

class Unit : public Weapon
{
protected:
	int HP;
	//Weapon weapon;
	int	speed;
	My_String name;
	bool IslnDefense;
public:
	Unit(const char* name_, int hp);
	Unit(int hp);
	Unit(const char* name_);
	~Unit();
	virtual void TakeDamage(int value);
	virtual void Atack(Unit& enemy);
	virtual void Defense();
	void Print() const;
};

class Swordman : public Unit
{
private:
	unsigned int power;

public:
	Swordman()
		:Unit("Den" , 1200)
	{
		damage += 20;
	}
	~Swordman();
	void Atack(Unit& enemy)override;
	void Defense()override;
	void TakeDamage(int value)override;


};

class Archer : public Unit
{
private:
	unsigned int arrows;

public:
	Archer()
		:Unit("Den", 1000)
	{
	}
	~Archer();
	void Atack(Unit& unit)override;
	void Defense()override;
	void TakeDamage(int value)override;

};


class Mage : public Unit
{
private:
	unsigned int mana;

public:
	Mage()
		:Unit("Den", 1000)
	{
		damage += 30;
	}
	~Mage();
	void Atack(Unit& unit)override;
	void Defense()override;
	void TakeDamage(int value)override;

};
