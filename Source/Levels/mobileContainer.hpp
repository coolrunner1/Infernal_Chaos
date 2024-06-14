#ifndef MOBILECONTAINER
#define MOBILECONTAINER
#include <iostream>
#include "../Entities/enemyMobile.hpp"
#include "../Entities/player.hpp"
#include "../Entities/bullet.hpp"

class mobileContainer {
    private:
        std::vector<enemyMobile> mobileEnemies;
        std::time_t current;
        sf::Vector2f playerPosition;
    public:
        void collisionMobile(sf::RenderWindow& window, std::time_t current, player* myPlayer, std::time_t* prevDamage);
        void clearVector();
        std::time_t pushEnemy();
        void collisionBullet(int increaseScore, sf::Vector2f bulletPosition, int shootingDamage, player* myPlayer);
        mobileContainer();
};
#endif
