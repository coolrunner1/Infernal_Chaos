#ifndef LEVELPATTERN
#define LEVELPATTERN
#include "Entities/player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class levelPattern{
    protected:
        player* myPlayer;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
    public:
        void movePlayer(sf::Event& event, sf::RenderWindow& window);
        void levelRender(sf::Event& event, sf::RenderWindow& window);
        void setBackground(sf::RenderWindow& window);
        void levelInit();
        levelPattern();
        levelPattern(std::string path);
        ~levelPattern();
};
#endif
