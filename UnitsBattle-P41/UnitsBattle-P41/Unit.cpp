#include "Unit.h"
#include <iostream>
namespace fighter {

	void Unit::SetHP(int value)
	{
		HP = value > 100 ? 100 : value < 0 ? 0 : value;
	}

	int Unit::GetHP() const
	{
		return HP;
	}

	const std::string& Unit::GetName() const
	{
		return name;
	}

	Unit::Unit(int HP, const std::string& name, const weapon::Weapon& weapon)
		:HP(HP), name(name), weapon(const_cast<weapon::Weapon*>(&weapon)), IsInDefense(false), armor(5)
	{}

	Unit::Unit(const Unit& other)
	{
		this->HP = other.HP;
		this->weapon = other.weapon->clone();
		this->speed = other.speed;
		this->name = other.name;
		this->IsInDefense = other.IsInDefense;
		this->armor = other.armor;
	}

	Unit::Unit(Unit&& other) noexcept
	{
		this->HP = other.HP;
		this->weapon = other.weapon;
		this->speed = other.speed;
		this->name = std::move(other.name);
		this->IsInDefense = other.IsInDefense;
		this->armor = other.armor;

		this->HP = 0;
		this->weapon = nullptr;
		this->speed = 0;
		this->name = std::move(other.name);
		this->IsInDefense = false;
		this->armor = 0;
	}

	int Unit::TakeDamage(int value)
	{
		int true_damage = IsInDefense ? value - armor : value;
		HP = HP - true_damage < 0 ? 0 : HP - true_damage;
		return true_damage;
	}

	bool Unit::IsDead() const
	{
		return HP <= 0;
	}

	void Unit::Defense()
	{
		IsInDefense = !IsInDefense;
	}

	void Unit::Print()
	{
		std::cout << "Unit " << name << std::endl;
	}
}