#ifndef NULL_ENEMIES_CONTAINER
#define NULL_ENEMIES_CONTAINER
#include "../EntityContainers/AbstractEnemyContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class NullEnemiesContainer : public AbstractEnemyContainer {
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void collides(sf::RenderWindow& window, Player& player);
        void collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets);
        void checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player);
        NullEnemiesContainer();
        ~NullEnemiesContainer();
};

#endif