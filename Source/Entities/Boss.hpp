#ifndef BOSS
#define BOSS
#include "CombinedEnemy.hpp"
#include <iostream>

class Boss : public CombinedEnemy {
    public:
        Boss(float transitionToSlowInterval, float transitionToFastInterval);
};
#endif
