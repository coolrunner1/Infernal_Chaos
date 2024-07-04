#ifndef CURSOR
#define CURSOR
#include "Entity.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class Cursor : public Entity{
    private:
        sf::Texture cursorTexture;
        sf::Sprite cursorSprite;
        sf::Vector2i cursorPosition;
    public:
        void cursorUpdate(sf::RenderWindow& window);
        Cursor();
};

#endif