#ifndef SFML_MAINMENU
#define SFML_MAINMENU
#include <SFML/Graphics.hpp>
#include <iostream>

class main_menu{
    private:
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        //sf::RenderWindow& internWindow;

    public:
        void mainMenuDraw(sf::RenderWindow& window);
        main_menu();
        
};
#endif