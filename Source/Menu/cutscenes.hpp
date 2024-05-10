#ifndef SFML_CUTSCENES
#define SFML_MAINMENU
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "button.hpp"
#define PAUSE 0
#define CREDITS -1

class cutscenes{
    private:
        sf::Texture backgroundTexture[4];
        sf::Sprite backgroundShape;
    public:
        void cutDraw(sf::Event& event, sf::RenderWindow& window, int screen);
        void scrDraw(sf::Event& event, sf::RenderWindow& window, int screen);
        cutscenes();
        ~cutscenes();
};
#endif