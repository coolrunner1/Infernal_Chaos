#ifndef NULL_ENTITIES_CONTAINER
#define NULL_ENTITIES_CONTAINER
#include "../EntityContainers/AbstractEntityContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class NullEntitiesContainer : public AbstractEntityContainer {
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void collides(sf::RenderWindow& window, Player& player);
        int getContainerLength();
        void clear();
        NullEntitiesContainer();
        ~NullEntitiesContainer();
};

#endif