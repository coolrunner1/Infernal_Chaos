#include "button.hpp"

void button::buttonDraw(float xpos, float ypos, float height, float width, std::string filePath, sf::RenderWindow& window){
    if (!buttonTexture.loadFromFile(filePath)) {
        std::cerr << "Missing file: " << filePath << std::endl;
    }
    buttonShape.setTexture(buttonTexture);
    buttonShape.setPosition(xpos, ypos);
    buttonShape.setScale(sf::Vector2f(width, height));
    window.draw(buttonShape);
}