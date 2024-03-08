#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class main_menu{
    private:
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        sf::RenderWindow& internWindow;

    public:
        int mainMenuDraw(sf::RenderWindow& window);
        /*main_menu(){

        }*/
        
};