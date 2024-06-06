#ifndef COMBINEDENEMY
#define COMBINEDENEMY
#include "armoredEnemy.hpp"
#include <iostream>

class combinedEnemy : public armoredEnemy{
    private:
        void combinedEnemyInit();
    protected:
        std::time_t transition;
    public:
        std::time_t setHighSpeed();
        std::time_t setLowSpeed();
        combinedEnemy();
        combinedEnemy(bool assasin);
};
#endif
