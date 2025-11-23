#ifndef MOBILE_ENEMIES_CONTAINER
#define MOBILE_ENEMIES_CONTAINER
#include "../Entities/EnemyMobile.hpp"
#include "../EntityContainers/AbstractEntityContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class MobileEnemiesContainer : public AbstractEntityContainer {
    private:
        std::vector<EnemyMobile> enemies;
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void collides(sf::RenderWindow& window, Player& player);
        std::vector<EnemyMobile>& getEntities();
        MobileEnemiesContainer(std::time_t start);
        ~MobileEnemiesContainer();
};

#endif