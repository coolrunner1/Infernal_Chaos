#ifndef ALIVEENTITY
#define ALIVEENTITY
#include "Entity.hpp"
#include <iostream>

class AliveEntity : public Entity{
    protected:
        int health;
        int armor;
        float speed;
    public:
        void healthDamage(int damage);
        int getHealth();
        int getArmor();
        AliveEntity();
        AliveEntity(int health, int armor);
};
#endif
