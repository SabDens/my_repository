#pragma once

class Weapon
{
private:
	char* name;
	int damage;
public:
	Weapon(const char* name, int damage);
	~Weapon();
	int GetDamage() const;
};