#ifndef AMMO_PACKS_CONTAINER
#define AMMO_PACKS_CONTAINER
#include "../Entities/AmmoPack.hpp"
#include "../EntityContainers/AbstractEntityContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class AmmoPacksContainer : public AbstractEntityContainer {
    private:
        std::vector<AmmoPack> ammoPacks;
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void update(sf::RenderWindow& window, Player& player);
        int getContainerLength();
        void clear();
        AmmoPacksContainer();
        ~AmmoPacksContainer();
};

#endif