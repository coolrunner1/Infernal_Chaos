#ifndef CURSOR
#define CURSOR
#include "entity.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class cursor : public entity{
    private:
        sf::Texture cursorTexture;
        sf::Sprite cursorSprite;
        sf::Vector2i cursorPosition;
    public:
        void cursorUpdate(sf::RenderWindow& window);
        cursor();
};

#endif