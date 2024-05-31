#ifndef ARMORPACK
#define ARMORPACK
//#include "pickup.hpp"
#include "entity.hpp"
#include <iostream>

class armorPack : public entity /*pickup*/{
    protected:
        int armor;
    public:
        int getArmor();
        armorPack();
        armorPack(int armor);
};
#endif
