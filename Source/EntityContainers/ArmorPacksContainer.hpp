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
        void spawnNewEntity(sf::RenderWindow& window, time_t& current);
        void collides(sf::RenderWindow& window, Player& player, time_t& current);
        std::vector<ArmorPack>* getArmorPacks();
        ArmorPacksContainer(std::time_t start);
        ~ArmorPacksContainer();
};

#endif