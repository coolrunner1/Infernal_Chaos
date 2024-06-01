#ifndef ARMOREDENEMY
#define ARMOREDENEMY
#include "enemy.hpp"

class armoredEnemy: public enemy {
    protected:
        std::time_t lastFired;
    public:
        void setFired(std::time_t fired);
        std::time_t getLastFired();
        void armoredInit();
        armoredEnemy();
        armoredEnemy(std::string path);
};
#endif
