#ifndef ARMOREDCONTAINER
#define ARMOREDCONTAINER
#include <iostream>
#include "../Entities/armoredEnemy.hpp"
#include "../Entities/player.hpp"
#include "../Entities/bullet.hpp"

class armoredContainer {
    private:
        std::vector<armoredEnemy> armoredEnemies;
        std::time_t current;
        std::time_t lastEnemy;
        sf::Vector2f playerPosition;
        int enemyFireInterval;
    public:
        void collisionMobile(sf::RenderWindow& window, std::time_t current, player* myPlayer, std::time_t* prevDamage);
        void clearVector();
        std::time_t pushEnemy();
        void collisionBullet(int increaseScore, sf::Vector2f bulletPosition, int shootingDamage, player* myPlayer);
        void collisionArmored(sf::RenderWindow& window, std::time_t current, sf::Vector2f playerPosition, std::vector<bullet>* enemyBullets, player* myPlayer, std::time_t* prevDamage, int enemyFireInterval);
        void collisionBoss(sf::RenderWindow& window, bool bossSpawned, std::time_t* assasinTransitionFirst, std::time_t* assasinTransitionSecond, float assasinInterval[2], std::time_t current, sf::Vector2f playerPosition, std::vector<bullet>* enemyBullets, player* myPlayer, std::time_t* prevDamage, int enemyFireInterval);
        void collidesBoss(sf::RenderWindow& window, player* myPlayer, std::time_t* prevDamage);
        void bossFiresABullet(sf::RenderWindow& window, std::vector<bullet>* enemyBullets);
        bool collisionBulletBoss(int increaseScore, bool bossSpawned, sf::Vector2f bulletPosition, int shootingDamage, player* myPlayer);
        armoredContainer();
};
#endif
