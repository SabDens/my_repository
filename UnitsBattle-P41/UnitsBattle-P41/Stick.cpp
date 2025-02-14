#include "Stick.h"
namespace weapon {
    Stick::Stick()
        : Weapon(30, "Stick", Grade::Common)
    {
    }

    void Stick::UpGrade()
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

    Weapon* Stick::clone() const
    {
        return new Stick(*this);
    }
}