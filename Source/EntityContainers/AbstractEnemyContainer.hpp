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
#define DAMAGE_INTERVAL 0.05

class AbstractEnemyContainer : public AbstractEntityContainer {
    private:
        std::vector<Enemy> entities;
    public:
        std::vector<Enemy>* getEntities();
        void collides(sf::RenderWindow& window, Player& player);
        virtual void collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets) = 0;
        AbstractEnemyContainer(std::time_t start);
};

#endif