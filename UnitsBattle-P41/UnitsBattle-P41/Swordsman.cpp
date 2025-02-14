#include "Swordsman.h"
#include "Sword.h"

namespace fighter {
	Swordsman::Swordsman()
		:Unit(100, "Swordsman", weapon::Sword()), power(5)
	{
	}

	Swordsman::Swordsman(const Swordsman& other)
		: Unit(other)
	{
		this->power = other.power;
	}

	void Swordsman::Attack(Unit& enemy)
	{
		int damage = enemy.TakeDamage(weapon->GetDamage());
		std::cout << "Swordsman: " << name << " Attack: " << enemy.GetName() << " Damage: (" << damage << ")" << std::endl;
		if (enemy.IsDead())
		{
			SetHP(HP + 25);
			std::cout << enemy.GetName() << " is dead" << std::endl;
		}
	}

	Unit* Swordsman::clone() const
	{
		return new Swordsman(*this);
	}
}