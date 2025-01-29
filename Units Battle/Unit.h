#pragma once
#include "Weapon.h"
#include "IPrint.h"
#include "Position.h"

class Unit : public IPrint
{
protected:
	int range;
	char* name;
	int hp;
	Weapon* weapon;
	Position position;
public:
	Unit(const char* name, int hp, Weapon* weapon, const Position& pos);

	virtual ~Unit() = 0;

	void Damaged(int value);

	int GetHP() const;

	const char* GetName() const;

	void SetPosition(Position& position);

	const Position& GetPosition() const;

	virtual void Attack(Unit& enemy);

	virtual void print() const override = 0;
};