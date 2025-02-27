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
        void spawnNewEntity(sf::RenderWindow& window, time_t& current);
        void collides(sf::RenderWindow& window, Player& player, time_t& current);
        std::vector<AmmoPack>* getAmmoPacks();
        AmmoPacksContainer(std::time_t start);
        ~AmmoPacksContainer();
};

#endif