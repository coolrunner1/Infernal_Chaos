#ifndef HEALTHPACKCONTAINER
#define HEALTHPACKCONTAINER
#include <iostream>
#include "../Entities/healthPack.hpp"
#include "../Entities/player.hpp"
#include "../Entities/bullet.hpp"

class healthPackContainer {
    private:
        std::vector<healthPack> healthPacks;
        std::time_t current;
        sf::Vector2f playerPosition;
        int enemyFireInterval;
    public:
        void collisionHealth(sf::RenderWindow& window, player* myPlayer, sf::Vector2f playerPosition);
        void clearVector();
        std::time_t pushPack();
        healthPackContainer();
};
#endif
