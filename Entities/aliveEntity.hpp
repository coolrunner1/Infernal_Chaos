#ifndef ALIVEENTITY
#define ALIVEENTITY
#include "entity.hpp"
#include <iostream>

class aliveEntity : public entity{
    protected:
        int health;
        int armor;
    public:
        void healthDamage(int damage);
        //void
        aliveEntity();
        aliveEntity(int health, int armor);
};
#endif
