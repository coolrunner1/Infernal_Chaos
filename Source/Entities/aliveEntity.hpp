#ifndef ALIVEENTITY
#define ALIVEENTITY
#include "entity.hpp"
#include <iostream>

class aliveEntity : public entity{
    protected:
        int health;
        int armor;
        float speed;
    public:
        void healthDamage(int damage);
        int getHealth();
        aliveEntity();
        aliveEntity(int health, int armor);
};
#endif
