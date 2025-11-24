#ifndef COMBINED_ENEMIES_CONTAINER
#define COMBINED_ENEMIES_CONTAINER
#include "../Entities/CombinedEnemy.hpp"
#include "../EntityContainers/AbstractEnemyContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class CombinedEnemiesContainer : public AbstractEnemyContainer {
    private:
        std::vector<CombinedEnemy> enemies;
        float assasinTransitionToSlowInterval;
        float assasinTransitionToFastInterval;
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void update(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets);
        void checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, Player& player);
        int getContainerLength();
        void clear();
        CombinedEnemiesContainer(float spawnInterval, float assasinTransitionToSlowInterval, float assasinTransitionToFastInterval);
        ~CombinedEnemiesContainer();
};

#endif