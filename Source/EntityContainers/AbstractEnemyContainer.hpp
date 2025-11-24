#ifndef ABSTRACT_ENEMY_CONTAINER
#define ABSTRACT_ENEMY_CONTAINER
#include "../Entities/Player.hpp"
#include "../Entities/Enemy.hpp"
#include "../Entities/Bullet.hpp"
#include "./AbstractEntityContainer.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class AbstractEnemyContainer : public AbstractEntityContainer {
    private:
        void collides(sf::RenderWindow& window, Player& player);
    public:
        virtual void collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets) = 0;
        virtual void checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player) = 0;
        AbstractEnemyContainer();
};

#endif