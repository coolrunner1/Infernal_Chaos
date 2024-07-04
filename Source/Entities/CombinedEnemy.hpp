#ifndef COMBINEDENEMY
#define COMBINEDENEMY
#include "ArmoredEnemy.hpp"
#include <iostream>

class CombinedEnemy : public ArmoredEnemy{
    private:
        void combinedEnemyInit();
    protected:
        std::time_t transition;
    public:
        std::time_t setHighSpeed();
        std::time_t setLowSpeed();
        CombinedEnemy();
        CombinedEnemy(bool assasin);
};
#endif
