#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "aliveEntity.hpp"

class player : public aliveEntity{
    private:
        int health;
        int armor;
        sf::Vector2f playerPosition;
        sf::Vector2i cursorPosition;
        sf::Texture cursorTexture;
        sf::Sprite cursor;
    public:
        void playerMove(sf::Event& event, sf::RenderWindow& window);
        player();
};
#endif
