#ifndef GAMEPAUSE
#define GAMEPAUSE
#include <SFML/Graphics.hpp>

class stillScreen{
    private:
        sf::Texture gameoverTexture;
        sf::Sprite gameoverShape;
        sf::Texture pauseTexture;
        sf::Sprite pauseShape;
        sf::Texture winTexture;
        sf::Sprite winShape;
    public:
        void pause(sf::Window window);
        void gameOver(sf::Window window);
        void youWin(sf::Window window);
        stillScreen();
}
#endif