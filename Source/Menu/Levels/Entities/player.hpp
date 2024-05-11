#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "aliveEntity.hpp"

class player : public aliveEntity{
    private:
        int health;
        int armor;
        sf::Vector2f playerPosition;
    public:
        void playerMove(sf::Event& event, sf::RenderWindow& window);
        player();
};
#endif
