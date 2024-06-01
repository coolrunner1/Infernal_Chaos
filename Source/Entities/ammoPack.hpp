#ifndef AMMOPACK
#define AMMOPACK
#include "entity.hpp"
#include <iostream>

class ammoPack : public entity {
    protected:
        int ammo;
    public:
        int getAmmo();
        ammoPack();
        ammoPack(int ammo);
};
#endif
