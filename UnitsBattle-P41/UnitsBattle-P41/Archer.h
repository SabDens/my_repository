#pragma once
#include "Unit.h"
namespace fighter {
    class Archer :
        public Unit
    {
    private:
        unsigned int arrows;
    public:
        Archer();
        Archer(const Archer& other);
        void Attack(Unit& enemy) override;
        virtual Unit* clone() const override;
    };
}
