#ifndef BULLET
#define BULLET
#include "aliveEntity.hpp"
#include <cmath>
#include <iostream>
#include <chrono>
#include <ctime>

class bullet : public aliveEntity{
    private:
        sf::Vector2f targetPos;
        sf::Vector2f bulletStart;
        sf::Vector2f bulletEnd;
        sf::Vector2f bulletPos;
        float angle;
        float bulletAngle;
        std::time_t start;
        std::time_t current;
    public:
        void bulletSet(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2i cursorPos);
        sf::Vector2f bulletMove();
        //bool bulletReachedEnd;
        bool bulletLifeCycle();
        std::time_t getTime();
        bullet();
};
/*class aliveEntity : public entity{
    protected:
        int health;
        int armor;
        float speed;
    public:
        void healthDamage(int damage);
        aliveEntity();
        aliveEntity(int health, int armor);
};*/

#endif