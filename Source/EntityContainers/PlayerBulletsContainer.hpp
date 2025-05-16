#ifndef PLAYER_BULLETS_CONTAINER
#define PLAYER_BULLETS_CONTAINER
#include "../Entities/EnemyMobile.hpp"
#include "../EntityContainers/AbstractEntityContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class PlayerBulletsContainer {
    private:
        std::vector<EnemyMobile> mobileEnemies;
    public:
        void spawnNewEntity(sf::RenderWindow& window, time_t& current);
        void collides(sf::RenderWindow& window, Player& player, time_t& current);
        std::vector<EnemyMobile>* getMobileEnemies();
        PlayerBulletsContainer(std::time_t start);
        ~PlayerBulletsContainer();
};

#endif