#ifndef ENEMYMOBILE
#define ENEMYMOBILE
#include "aliveEntity.hpp"
#include <iostream>

class enemyMobile : public aliveEntity{
    protected:
        /*int health;
        int armor;*/
    public:
        void enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos);
        /*aliveEntity();
        aliveEntity(int health, int armor);*/
        enemyMobile();
};
#endif
