#ifndef SFML_MAINMENU
#define SFML_MAINMENU
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "button.hpp"
#define numOfButtons 10
#define MAIN_MENU 0
#define PLAY_MENU 1
#define INFERNAL_CAMPAIGN 2
#define PERPETUAL_SUFFERING_MENU 3
#define PS_LVL_1 4
#define PS_LVL_2 5
#define PS_LVL_3 6

class main_menu{
    private:
        sf::Texture backgroundTexture[4];
        sf::Sprite backgroundShape;
        //button butPlay;
        std::string path[numOfButtons];
        //button buttons[numOfButtons];
        button* buttons[numOfButtons];
    public:
        void mainMenuDraw(int screen, sf::RenderWindow& window);
        //void secondMenuDraw(sf::RenderWindow& window);
        int mainButtons(sf::Event& event, sf::RenderWindow& window, int screen);
        //int secButtons(sf::Event& event, sf::RenderWindow& window);
        void menuButtons(sf::RenderWindow& window);
        void secondScrButtons(sf::RenderWindow& window);
        void thirdScrButtons(sf::RenderWindow& window);
        main_menu();
        ~main_menu();
};
#endif
