#pragma once
#include <vector>
#include "Unit.h"
#include <initializer_list>
class Team
{
protected:
	std::string name;
	static bool isFirst;
	std::vector<fighter::Unit*> units;
	fighter::Unit& GetRandomTarget(Team& targets);
public:
	Team();
	//Team(std::initializer_list<const Unit&> list);
	void SetName(const std::string& value);
	const std::string& GetName() const;
	void Append(const fighter::Unit& unit);
	void Attack(Team& enemies);
	bool IsDead() const;
	void Defense();
	int Size() const;
	int aLive() const;
};