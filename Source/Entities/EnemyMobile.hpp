#ifndef ENEMYMOBILE
#define ENEMYMOBILE
#include "Enemy.hpp"
#include <iostream>

class EnemyMobile : public Enemy {
    private:
        void enemyMobileInit();
    public:
        EnemyMobile();
        EnemyMobile(bool rascal);
};

#endif
