#ifndef LEVELPATTERN
#define LEVELPATTERN
#include "Entities/player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class levelPattern{
    protected:
        player* myPlayer;
        
    public:
        void movePlayer(sf::Event& event, sf::RenderWindow& window);
        void levelRender(sf::Event& event, sf::RenderWindow& window);
        levelPattern();
        ~levelPattern();
};
#endif
