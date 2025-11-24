#ifndef MOBILE_ENEMIES_CONTAINER
#define MOBILE_ENEMIES_CONTAINER
#include "../Entities/EnemyMobile.hpp"
#include "../EntityContainers/AbstractEnemyContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class MobileEnemiesContainer : public AbstractEnemyContainer {
    private:
        std::vector<EnemyMobile> enemies;
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void update(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets);
        void checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player);
        int getContainerLength();
        void clear();
        MobileEnemiesContainer(float spawnInterval);
        ~MobileEnemiesContainer();
};

#endif