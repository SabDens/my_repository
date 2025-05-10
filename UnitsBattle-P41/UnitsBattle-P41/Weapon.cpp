#include "Weapon.h"
#include <iostream>
namespace weapon {

    Weapon::Weapon(const Weapon& other)
    {
        this->damage = other.damage;
        this->grade = other.grade;
        this->name = other.name;
    }

    Weapon::Weapon(Weapon&& other) noexcept
    {
        this->damage = other.damage;
        this->grade = other.grade;
        this->name = std::move(other.name);
    }

    Weapon::Weapon(unsigned int damage, const std::string& name, Grade grade)
        :damage(damage), name(name), grade(grade)
    {
    }

    unsigned int Weapon::GetDamage()
    {
        return damage;
    }

    //void Weapon::UpGrage()
    //{
    //    switch (grade)
    //    {
    //    case Common:
    //        damage += 5;
    //        grade = Rare;
    //        break;
    //    case Rare:
    //        damage += 5;
    //        grade = Epic;
    //        break;
    //    case Epic:
    //        damage += 5;
    //        grade = Legendary;
    //        break;
    //    case Legendary:
    //        damage += 5;
    //        grade = Rare;
    //        break;
    //    case Mythic:
    //        damage += 5;
    //        break;
    //    }
    //}

    Grade Weapon::GetGrade()
    {
        return grade;
    }
}