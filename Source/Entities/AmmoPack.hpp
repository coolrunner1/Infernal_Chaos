#ifndef AMMOPACK
#define AMMOPACK
#include "Entity.hpp"
#include <iostream>

class AmmoPack : public Entity {
    private:
        int ammo;
    public:
        int getAmmo();
        AmmoPack();
};
#endif
