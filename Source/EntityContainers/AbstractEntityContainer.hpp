#ifndef ABSTRACT_ENTITY_CONTAINER
#define ABSTRACT_ENTITY_CONTAINER
#include "../Entities/Player.hpp"
#include "../Entities/Entity.hpp"
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
        virtual void spawnNewEntity(sf::RenderWindow& window) = 0;
        virtual void update(sf::RenderWindow& window, Player& player) = 0;
        virtual int getContainerLength() = 0;
        virtual void clear() = 0;
        time_t getLastSpawnedTimestamp();
        void setLastSpawnedTimestamp(std::time_t& timestamp);
        void setSpawnInterval (float spawnInterval);
        float getSpawnInterval();
        AbstractEntityContainer();
        ~AbstractEntityContainer();
};

#endif