#ifndef BOSS_CONTAINER
#define BOSS_CONTAINER
#include "../Entities/Boss.hpp"
#include "../EntityContainers/AbstractEnemyContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class BossContainer : public AbstractEnemyContainer {
    private:
        Boss* boss;
        bool defeated;
        float assasinTransitionToSlowInterval;
        float assasinTransitionToFastInterval;
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void update(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets);
        void checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, Player& player);
        int getContainerLength();
        void clear();
        BossContainer(float assasinTransitionToSlowInterval, float assasinTransitionToFastInterval);
        ~BossContainer();
};

#endif