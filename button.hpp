#ifndef SFML_BUTTON
#define SFML_BUTTON
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class button{
    private:
        sf::Texture buttonTexture;
        sf::Sprite buttonShape;
        //sf::RectangleShape buttonArea;

    public:
        void buttonDraw(float xpos, float ypos, float height, float width, std::string filePath, sf::RenderWindow& window);
        button();
        ~button();
};
#endif