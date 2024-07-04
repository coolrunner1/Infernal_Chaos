#ifndef ARMORPACK
#define ARMORPACK
#include "Entity.hpp"
#include <iostream>

class ArmorPack : public Entity {
    private:
        int armor;
    public:
        int getArmor();
        ArmorPack();
};
#endif
