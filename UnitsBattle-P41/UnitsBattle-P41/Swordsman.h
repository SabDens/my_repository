#pragma once
#include "Unit.h"
namespace fighter {
	class Swordsman : public Unit
	{
	private:
		unsigned int power;
	public:
		Swordsman();
		Swordsman(const Swordsman& other);
		void Attack(Unit& enemy) override;
		virtual Unit* clone() const override;
	};
}
