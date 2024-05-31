#include "entity.hpp"

entity::entity(){
    /*xpos=0;
    ypos=0;*/
    xpos=generateRandomFloat(COLLISION_LEFT, COLLISION_RIGHT);
    ypos=generateRandomFloat(COLLISION_TOP, COLLISION_BOTTOM);
    entityInit();
}

void entity::entityDraw(sf::RenderWindow& window){
    window.draw(entitySprite);
}

entity::entity(int xpos, int ypos, std::string path){
    this->xpos=xpos;
    this->ypos=ypos;
    this->path=path;
    setSprite(path);
    entityInit();
}

void entity::setSprite(std::string path){
    if (!entityTexture.loadFromFile(path)) {
        std::cerr << "Missing file: "<< path << std::endl;
    }
    entitySprite.setTexture(entityTexture);
}

void entity::entityInit(){
    entitySprite.setPosition(sf::Vector2f(xpos, ypos));
}

void entity::entityMove(int xpos, int ypos){
    this->xpos=xpos;
    this->ypos=ypos;
    entitySprite.setPosition(sf::Vector2f(xpos, ypos));
}