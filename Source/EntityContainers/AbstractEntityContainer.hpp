#ifndef ABSTRACT_ENTITY_CONTAINER
#define ABSTRACT_ENTITY_CONTAINER
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class AbstractEntityContainer {
    private:
        float spawnInterval;
        std::time_t lastSpawnedTimestamp;
    public:
        void spawnNewEntity(sf::RenderWindow& window, time_t& current);
        void collides(sf::RenderWindow& window, Player& player, time_t& current);
        time_t getLastSpawnedTimestamp();
        void setLastSpawnedTimestamp(std::time_t& timestamp);
        void setSpawnInterval (float spawnInterval);
        float getSpawnInterval();
        AbstractEntityContainer(std::time_t start);
};

#endif