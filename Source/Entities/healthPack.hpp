#ifndef HEALTHPACK
#define HEALTHPACK
#include "entity.hpp"
#include <iostream>

class healthPack : public entity /*pickup*/{
    protected:
        int health;
    public:
        int getHealth();
        healthPack();
};
#endif
