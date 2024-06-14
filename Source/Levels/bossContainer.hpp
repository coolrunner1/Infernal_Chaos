#ifndef BOSSCONTAINER
#define BOSSCONTAINER
#include <iostream>
#include "../Entities/boss.hpp"
#include "../Entities/player.hpp"
#include "../Entities/bullet.hpp"

class bossContainer {
    private:
        boss bossFinal;
        std::time_t current;
        sf::Vector2f playerPosition;
        int enemyFireInterval;
    public:
        void collisionBoss(sf::RenderWindow& window, bool bossSpawned, std::time_t* assasinTransitionFirst, std::time_t* assasinTransitionSecond, float assasinInterval[2], std::time_t current, sf::Vector2f playerPosition, std::vector<bullet>* enemyBullets, player* myPlayer, std::time_t* prevDamage, int enemyFireInterval);
        void collidesBoss(sf::RenderWindow& window, player* myPlayer, std::time_t* prevDamage);
        void bossFiresABullet(sf::RenderWindow& window, std::vector<bullet>* enemyBullets);
        bool collisionBulletBoss(int increaseScore, bool bossSpawned, sf::Vector2f bulletPosition, int shootingDamage, player* myPlayer);
        bossContainer();
};
#endif
