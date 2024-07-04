#ifndef SFML_BUTTON
#define SFML_BUTTON
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Button{
    private:
        sf::Texture buttonTexture;
        sf::Sprite buttonShape;
        std::string filePath;

    public:
        void buttonDraw(float xpos, float ypos, float height, float width, sf::RenderWindow& window);
        bool isClicked(sf::RenderWindow& window);
        Button();
        Button(std::string filePath);
};
#endif