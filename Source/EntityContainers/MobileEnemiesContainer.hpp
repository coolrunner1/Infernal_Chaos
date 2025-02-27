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
        std::vector<EnemyMobile> mobileEnemies;
    public:
        void spawnNewEntity(sf::RenderWindow& window, time_t& current);
        void collides(sf::RenderWindow& window, Player& player, time_t& current);
        std::vector<EnemyMobile>* getMobileEnemies();
        MobileEnemiesContainer(std::time_t start);
        ~MobileEnemiesContainer();
};

#endif