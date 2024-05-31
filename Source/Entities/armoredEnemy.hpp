#ifndef ARMOREDENEMY
#define ARMOREDENEMY
#include "enemy.hpp"

class armoredEnemy: public enemy /*pickup*/{
    protected:
        std::time_t lastFired;
    public:
        //int getArmor();
        void setFired(std::time_t fired);
        std::time_t getLastFired();
        void armoredInit();
        armoredEnemy();
        armoredEnemy(std::string path);
        //armorPack(int armor);
};
#endif
