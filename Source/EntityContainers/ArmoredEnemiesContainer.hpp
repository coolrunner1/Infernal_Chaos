#ifndef ARMORED_ENEMIES_CONTAINER
#define ARMORED_ENEMIES_CONTAINER
#include "../Entities/ArmoredEnemy.hpp"
#include "../EntityContainers/AbstractEnemyContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class ArmoredEnemiesContainer : public AbstractEnemyContainer {
    private:
        std::vector<ArmoredEnemy> enemies;
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets);
        void checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player);
        int getContainerLength();
        void clear();
        ArmoredEnemiesContainer();
        ~ArmoredEnemiesContainer();
};

#endif