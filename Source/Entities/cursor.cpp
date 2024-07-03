#include "cursor.hpp"

cursor::cursor() : entity(){
    if (!cursorTexture.loadFromFile("Sprites/Cursor.png")) {
                std::cerr << "Missing file: Sprites/Cursor.png"<<std::endl;
        }
        cursorSprite.setTexture(cursorTexture);
        cursorSprite.setScale(3, 3);
}

void cursor::cursorUpdate(sf::RenderWindow& window){
    cursorPosition=sf::Mouse::getPosition(window);
    cursorSprite.setPosition(cursorPosition.x-25, cursorPosition.y-25);
    window.draw(cursorSprite);
}