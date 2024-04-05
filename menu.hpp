#ifndef MENU
#define MENU
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "button.hpp"
#define maxNumOfButtons 5

class menu{
    private:
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        int numOfbuttons;
        //button butPlay;
        std::string path[maxNumOfButtons];
        //button buttons[numOfButtons];
        button* buttons[maxNumOfButtons];
    public:
        void mainMenuDraw(int screen, sf::RenderWindow& window);
        //void secondMenuDraw(sf::RenderWindow& window);
        int mainButtons(sf::Event& event, sf::RenderWindow& window, int screen);
        //int secButtons(sf::Event& event, sf::RenderWindow& window);
        void menuButtons(int min, int max, sf::RenderWindow& window);
        menu(std::string backPath, std::string butPath[], int butNum);
        menu();
        ~menu();
};
#endif