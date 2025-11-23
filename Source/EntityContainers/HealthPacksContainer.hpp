#ifndef HEALTH_PACKS_CONTAINER
#define HEALTH_PACKS_CONTAINER
#include "../Entities/HealthPack.hpp"
#include "../EntityContainers/AbstractEntityContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class HealthPacksContainer : public AbstractEntityContainer {
    private:
        std::vector<HealthPack> healthPacks;
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void collides(sf::RenderWindow& window, Player& player);
        std::vector<HealthPack>* getHealthPacks();
        HealthPacksContainer(std::time_t start);
        ~HealthPacksContainer();
};

#endif