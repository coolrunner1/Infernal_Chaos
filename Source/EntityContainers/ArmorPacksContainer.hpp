#ifndef ARMOR_PACKS_CONTAINER
#define ARMOR_PACKS_CONTAINER
#include "../Entities/ArmorPack.hpp"
#include "../EntityContainers/AbstractEntityContainer.hpp"
#include "../Entities/Player.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class ArmorPacksContainer : public AbstractEntityContainer {
    private:
        std::vector<ArmorPack> armorPacks;
    public:
        void spawnNewEntity(sf::RenderWindow& window);
        void collides(sf::RenderWindow& window, Player& player);
        ArmorPacksContainer();
        ~ArmorPacksContainer();
};

#endif