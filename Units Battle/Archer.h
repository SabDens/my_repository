#pragma once
#include "Unit.h"
#include "Bow.h"

class Archer : public Unit
{
private:
	int arrows;
public:
	Archer(const char* name, int hp, int arrows, Bow* bow);
	Archer(const char* name, int hp, int arrows, Bow* bow, Position& pos);

	virtual void Attack(Unit& enemy);

	~Archer() = default;

	void print() const override;
};