#include "entity.hpp"

entity::entity(){
    xpos=0;
    ypos=0;
    entityInit();
}

void entity::entityDraw(sf::RenderWindow& window){
    window.draw(entitySprite);
}

entity::entity(int xpos, int ypos){
    this->xpos=xpos;
    this->ypos=ypos;
    entityInit();
}

void entity::entityInit(){
    if (!entityTexture.loadFromFile("Sprites/main_char_idle_0.png")) {
        std::cerr << "Missing file: Sprites/main_char_idle_0.png" << std::endl;
    }
    entitySprite.setTexture(entityTexture);
    entitySprite.setPosition(sf::Vector2f(xpos, ypos));
}

void entity::entityMove(int xpos, int ypos){
    this->xpos=xpos;
    this->ypos=ypos;
    entitySprite.setPosition(sf::Vector2f(xpos, ypos));
}