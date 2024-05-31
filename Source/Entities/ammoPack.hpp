#ifndef AMMOPACK
#define AMMOPACK
//#include "pickup.hpp"
#include "entity.hpp"
#include <iostream>

class ammoPack : public entity /*pickup*/{
    protected:
        int ammo;
    public:
        int getAmmo();
        ammoPack();
        ammoPack(int ammo);
};
#endif
