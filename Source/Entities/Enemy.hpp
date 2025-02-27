#ifndef ENEMY
#define ENEMY
#include "AliveEntity.hpp"
#include <iostream>

class Enemy : public AliveEntity {
    protected:
        int damage;
        std::time_t damageTime;
        std::string enemyPath[2];
    public:
        void enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos);
        int getDamage();
        void setDamageTime(std::time_t damageTime);
        std::time_t getDamageTime();
        Enemy();
};

#endif
