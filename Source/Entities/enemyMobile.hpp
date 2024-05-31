#ifndef ENEMYMOBILE
#define ENEMYMOBILE
#include "enemy.hpp"
#include <iostream>

class enemyMobile : public enemy{
    public:
        /*void enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos);
        int getDamage();*/
        enemyMobile();
        /*void setDamageTime(std::time_t damageTime);
        std::time_t getDamageTime();*/
};

#endif
