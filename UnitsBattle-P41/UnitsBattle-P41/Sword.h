#pragma once
#include "Weapon.h"
namespace weapon {
    class Sword :
        public Weapon
    {
    public:
        Sword();
        void UpGrade() override;
        virtual Weapon* clone() const override;
    };
}