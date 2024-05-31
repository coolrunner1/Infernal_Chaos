#ifndef ENEMYMOBILE
#define ENEMYMOBILE
#include "aliveEntity.hpp"
#include <iostream>

class enemyMobile : public aliveEntity{
    protected:
        /*int health;
        int armor;*/
        int damage;
    public:
        void enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos);
        /*aliveEntity();
        aliveEntity(int health, int armor);*/
        int getDamage();
        enemyMobile();
};
#endif
