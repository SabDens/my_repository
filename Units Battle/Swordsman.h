#pragma once
#include "Unit.h"
#include "Sword.h"
#include "Position.h"

class Swordsman : public Unit
{
private:
	int power;
public:
	Swordsman(const char* name, int power, Sword* sword);
	Swordsman(const char* name, int hp, int power, Sword* sword, Position& pos);

	virtual void Attack(Unit& enemy); // !!!

	~Swordsman() = default;

	void print() const override;
};