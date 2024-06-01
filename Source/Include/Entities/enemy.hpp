#ifndef ENEMY
#define ENEMY
#include "aliveEntity.hpp"
#include <iostream>

class enemy : public aliveEntity{
    protected:
        int damage;
        std::time_t damageTime;
        std::string enemyPath[2];
    public:
        void enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos);
        int getDamage();
        enemy();
        void setDamageTime(std::time_t damageTime);
        std::time_t getDamageTime();
};

#endif
