#include "Button.hpp"

void Button::buttonDraw(float xpos, float ypos, float height, float width, sf::RenderWindow& window){
    if (!buttonTexture.loadFromFile(filePath)) {
        std::cerr << "Missing file: " << filePath << std::endl;
    }
    buttonShape.setTexture(buttonTexture);
    buttonShape.setPosition(xpos, ypos);
    buttonShape.setScale(sf::Vector2f(width, height));
    window.draw(buttonShape);
}

bool Button::isClicked(sf::RenderWindow& window){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::FloatRect buttonBounds = buttonShape.getGlobalBounds();

    return buttonBounds.contains(static_cast<sf::Vector2f>(mousePosition));
}

Button::Button(){
    std::cerr<<"Object initialized incorrectly\n";
    std::string filePath="NO PATH";
}
Button::Button(std::string filePath){
    this->filePath=filePath;
}
