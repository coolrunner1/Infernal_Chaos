#include "cursor.hpp"

cursor::cursor() : entity(){
    if (!entityTexture.loadFromFile("Sprites/Cursor.png")) {
                std::cerr << "Missing file: Sprites/Cursor.png"<<std::endl;
        }
        entitySprite.setTexture(entityTexture);
        entitySprite.setScale(3, 3);
}

void cursor::cursorUpdate(sf::RenderWindow& window){
    cursorPosition=sf::Mouse::getPosition(window);
    entitySprite.setPosition(cursorPosition.x-25, cursorPosition.y-25);
    window.draw(entitySprite);
}