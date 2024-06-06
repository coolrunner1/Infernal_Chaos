#ifndef ENEMYMOBILE
#define ENEMYMOBILE
#include "enemy.hpp"
#include <iostream>

class enemyMobile : public enemy{
    private:
        void enemyMobileInit();
    public:
        enemyMobile();
        enemyMobile(bool rascal);
};

#endif
