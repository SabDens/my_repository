#include "Archer.h"
#include "Bow.h"
#include <iostream>
namespace fighter {

	Archer::Archer()
		: Unit(100, "Archer", weapon::Bow()), arrows(10)
	{
	}

	Archer::Archer(const Archer& other)
		: Unit(other)
	{
		this->arrows = other.arrows;
	}

	void Archer::Attack(Unit& enemy)
	{
		if (arrows > 0)
		{
			arrows--;
			int damage = enemy.TakeDamage(weapon->GetDamage());
			std::cout << "Archer: " << name << " Attack: " << enemy.GetName() << " Damage: (" << damage << ")" << std::endl;
			if (enemy.IsDead())
			{
				arrows += 5;
				std::cout << enemy.GetName() << " is dead" << std::endl;
			}
		}
		else {
			std::cout << "Archer: " << name << " No arrows" << std::endl;
		}
	}

	Unit* Archer::clone() const
	{
		return new Archer(*this);
	}
}