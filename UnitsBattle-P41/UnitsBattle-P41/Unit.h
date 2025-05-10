#pragma once
#include <iostream>
#include "Weapon.h"

namespace fighter {
	class Unit
	{
	protected:
		int HP;
		weapon::Weapon* weapon;
		unsigned int speed;
		std::string name;
		bool IsInDefense;
		int armor;
	public:
		void SetHP(int value);
		int GetHP() const;
		const std::string& GetName() const;
		Unit(int HP, const std::string& name, const weapon::Weapon& weapon);
		Unit(const Unit& other);
		Unit(Unit&& other) noexcept;
		virtual void Attack(Unit& enemy) = 0;
		virtual int TakeDamage(int value);
		bool IsDead() const;
		virtual void Defense();
		virtual void Print();
		virtual Unit* clone() const = 0;
	};
}
