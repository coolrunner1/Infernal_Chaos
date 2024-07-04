#ifndef HEALTHPACK
#define HEALTHPACK
#include "Entity.hpp"
#include <iostream>

class HealthPack : public Entity {
    private:
        int health;
    public:
        int getHealth();
        HealthPack();
};
#endif
