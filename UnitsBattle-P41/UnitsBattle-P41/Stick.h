#pragma once
#include "Weapon.h"
namespace weapon {

    class Stick :
        public Weapon
    {
    protected:
    public:
        Stick();
        void UpGrade() override;
        virtual Weapon* clone() const override;
    };
}