#include "Mage.h"
#include "Stick.h"
namespace fighter {

	Mage::Mage()
		: Unit(100, "Mage", weapon::Stick()), mana(100)
	{
	}

	Mage::Mage(const Mage& other)
		: Unit(other)
	{
		this->mana = other.mana;
	}

	void Mage::Attack(Unit& enemy)
	{
		if (mana - 15 > 0)
		{
			mana -= 15;
			int damage = enemy.TakeDamage(weapon->GetDamage());
			std::cout << "Mage: " << name << " Attack: " << enemy.GetName() << " Damage: (" << damage << ")" << std::endl;
			if (enemy.IsDead())
			{
				mana = mana + 30 > 100 ? 100 : mana + 30;
				std::cout << enemy.GetName() << " is dead" << std::endl;
			}
		}
		else {
			std::cout << "Mage: " << name << " No mana" << std::endl;
		}
	}

	Unit* Mage::clone() const
	{
		return new Mage(*this);
	}
}