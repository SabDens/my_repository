#pragma once
#include <string>
namespace weapon {
	enum Grade
	{
		Common,
		Rare,
		Epic,
		Legendary,
		Mythic
	};

	class Weapon
	{
	protected:
		Grade grade;
		std::string name;
		unsigned int damage;
	public:
		Weapon(const Weapon& other);
		Weapon(Weapon&& other) noexcept;
		Weapon(unsigned int damage, const std::string& name, Grade grade);
		unsigned int GetDamage();
		virtual void UpGrade() = 0;
		Grade GetGrade();
		virtual Weapon* clone() const = 0;
	};
}
