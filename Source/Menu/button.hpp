#ifndef SFML_BUTTON
#define SFML_BUTTON
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class button{
    private:
        sf::Texture buttonTexture;
        sf::Sprite buttonShape;
        std::string filePath;

    public:
        void buttonDraw(float xpos, float ypos, float height, float width, sf::RenderWindow& window);
        void buttonDrawText(float xpos, float ypos, float height, float width, std::string filePath, sf::RenderWindow& window);
        bool isClicked(sf::RenderWindow& window);
        button();
        button(std::string filePath);
};
#endif