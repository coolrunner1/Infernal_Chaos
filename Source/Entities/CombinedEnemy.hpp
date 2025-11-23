#ifndef COMBINEDENEMY
#define COMBINEDENEMY
#include "ArmoredEnemy.hpp"
#include <iostream>

class CombinedEnemy : public ArmoredEnemy {
    private:
        void combinedEnemyInit();
        std::time_t transitionToSlowTimestamp;
        std::time_t transitionToFastTimestamp;
    public:
        std::time_t getTransitionToSlowTimestamp();
        std::time_t getTransitionToFastTimestamp();
        void updateTransitionToSlowTimestamp();
        void updateTransitionToFastTimestamp();
        void setHighSpeed();
        void setLowSpeed();
        CombinedEnemy();
        CombinedEnemy(bool assasin);
};
#endif
