#include "Bow.h"
namespace weapon {
    Bow::Bow()
        : Weapon(20, "Bow", Grade::Common)
    {
    }

    void Bow::UpGrade()
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

    Weapon* Bow::clone() const
    {
        return new Bow(*this);
    }
}