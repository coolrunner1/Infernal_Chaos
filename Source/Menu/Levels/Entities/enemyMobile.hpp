#ifndef ENEMYMOBILE
#define ENEMYMOBILE
#include "aliveEntity.hpp"
#include <iostream>

class enemyMobile : public aliveEntity{
    protected:
        /*int health;
        int armor;*/
    public:
        void enemyMove(sf::RenderWindow window);
        /*aliveEntity();
        aliveEntity(int health, int armor);*/
        enemyMobile();
};
#endif
