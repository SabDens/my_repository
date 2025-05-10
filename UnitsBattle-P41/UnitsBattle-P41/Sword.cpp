#include "Sword.h"
namespace weapon {
    Sword::Sword()
        : Weapon(10, "Sword", Grade::Common)
    {
    }

    void Sword::UpGrade()
    {
        switch (grade)
        {
        case Common:
            damage += 5;
            grade = Rare;
            break;
        case Rare:
            damage += 5;
            grade = Epic;
            break;
        case Epic:
            damage += 5;
            grade = Legendary;
            break;
        case Legendary:
            damage += 5;
            grade = Rare;
            break;
        case Mythic:
            damage += 5;
            break;
        }
    }

    Weapon* Sword::clone() const
    {
        return new Sword(*this);
    }
}