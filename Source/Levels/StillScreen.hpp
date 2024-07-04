#ifndef GAMEPAUSE
#define GAMEPAUSE
#include <SFML/Graphics.hpp>
#include <iostream>

class StillScreen{
    private:
        sf::Texture gameoverTexture;
        sf::Sprite gameoverShape;
        sf::Texture pauseTexture;
        sf::Sprite pauseShape;
        sf::Texture winTexture;
        sf::Sprite winShape;
    public:
        void pause(sf::RenderWindow& window);
        void gameOver(sf::RenderWindow& window);
        void youWin(sf::RenderWindow& window);
        StillScreen();
};
#endif