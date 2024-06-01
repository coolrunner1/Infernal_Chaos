#ifndef ARMORPACK
#define ARMORPACK
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
