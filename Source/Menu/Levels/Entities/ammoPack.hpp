#ifndef AMMOPACK
#define AMMOPACK
#include "pickup.hpp"
#include <iostream>

class ammoPack : public pickup{
    protected:
        int ammo;
    public:
        ammoPack();
        ammoPack(int ammo);
};
#endif
