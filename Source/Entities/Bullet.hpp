#ifndef BULLET
#define BULLET
#include "AliveEntity.hpp"
#include <cmath>
#include <iostream>


class Bullet : public AliveEntity {
    private:
        sf::Vector2f targetPos;
        sf::Vector2f bulletStart;
        sf::Vector2f bulletEnd;
        sf::Vector2f bulletPos;
        float angle;
        float bulletAngle;
        std::time_t current;
    public:
        void bulletSet(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2i cursorPos);
        void setupBullet(sf::RenderWindow& window, sf::Vector2f playerPos);
        sf::Vector2f bulletMove();
        void bulletSetFloat(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2f endPos);
        bool bulletLifeCycleExpired();
        Bullet();
};

#endif