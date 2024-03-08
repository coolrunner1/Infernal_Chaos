#ifndef SFML_MAINMENU
#define SFML_MAINMENU
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "button.hpp"

class main_menu{
    private:
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        button buttons[2];

    public:
        void mainMenuDraw(sf::RenderWindow& window);
        int mainButtons(sf::Event& event, sf::RenderWindow& window);
        main_menu();
        //~main_menu();
};
#endif