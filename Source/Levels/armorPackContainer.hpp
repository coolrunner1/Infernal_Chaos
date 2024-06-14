#ifndef ARMORPACKCONTAINER
#define ARMORPACKCONTAINER
#include <iostream>
#include "../Entities/armorPack.hpp"
#include "../Entities/player.hpp"
#include "../Entities/bullet.hpp"

class armorPackContainer {
    private:
        std::vector<armorPack> armorPacks;
        std::time_t current;
        sf::Vector2f playerPosition;
        int enemyFireInterval;
    public:
        void collisionArmor(sf::RenderWindow& window, player* myPlayer, sf::Vector2f playerPosition);
        void clearVector();
        std::time_t pushPack();
        armorPackContainer();
};
#endif
