#ifndef ABSTRACT_ENTITY_CONTAINER
#define ABSTRACT_ENTITY_CONTAINER
#include "../Entities/Player.hpp"
#include "../Entities/Entity.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#define DAMAGE_INTERVAL 0.05

class AbstractEntityContainer {
    private:
        float spawnInterval;
        std::time_t lastSpawnedTimestamp;
    public:
        virtual void spawnNewEntity(sf::RenderWindow& window) = 0;
        virtual void collides(sf::RenderWindow& window, Player& player) = 0;
        time_t getLastSpawnedTimestamp();
        void setLastSpawnedTimestamp(std::time_t& timestamp);
        void setSpawnInterval (float spawnInterval);
        float getSpawnInterval();
        AbstractEntityContainer();
        ~AbstractEntityContainer();
};

#endif