#ifndef AMMOPACKCONTAINER
#define AMMOPACKCONTAINER
#include <iostream>
#include "../Entities/ammoPack.hpp"
#include "../Entities/player.hpp"
#include "../Entities/bullet.hpp"

class ammoPackContainer {
    private:
        std::vector<ammoPack> ammoPacks;
        std::time_t current;
        sf::Vector2f playerPosition;
        int enemyFireInterval;
    public:
        void collisionAmmo(sf::RenderWindow& window, player* myPlayer, sf::Vector2f playerPosition);
        void clearVector();
        std::time_t pushPack();
        ammoPackContainer();
};
#endif
