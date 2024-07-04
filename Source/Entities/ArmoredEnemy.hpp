#ifndef ARMOREDENEMY
#define ARMOREDENEMY
#include "Enemy.hpp"

class ArmoredEnemy: public Enemy {
    private:
        void armoredInit();
    protected:
        std::time_t lastFired;
    public:
        void setFired(std::time_t fired);
        std::time_t getLastFired();
        ArmoredEnemy();
        ArmoredEnemy(bool robot);
};
#endif
