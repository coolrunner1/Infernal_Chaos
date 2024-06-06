#ifndef ARMOREDENEMY
#define ARMOREDENEMY
#include "enemy.hpp"

class armoredEnemy: public enemy {
    private:
        void armoredInit();
    protected:
        std::time_t lastFired;
    public:
        void setFired(std::time_t fired);
        std::time_t getLastFired();
        armoredEnemy();
        armoredEnemy(bool robot);
};
#endif
