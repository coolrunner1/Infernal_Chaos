#ifndef HEALTHPACK
#define HEALTHPACK
#include "entity.hpp"
#include <iostream>

class healthPack : public entity {
    private:
        int health;
    public:
        int getHealth();
        healthPack();
};
#endif
