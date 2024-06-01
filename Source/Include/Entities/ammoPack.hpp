#ifndef AMMOPACK
#define AMMOPACK
#include "entity.hpp"
#include <iostream>

class ammoPack : public entity {
    private:
        int ammo;
    public:
        int getAmmo();
        ammoPack();
        ammoPack(int ammo);
};
#endif
