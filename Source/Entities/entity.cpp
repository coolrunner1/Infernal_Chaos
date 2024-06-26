#include "entity.hpp"

entity::entity(){
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
    std::time(&start);
    entitySprite.setPosition(sf::Vector2f(xpos, ypos));
}

void entity::entityMove(int xpos, int ypos){
    this->xpos=xpos;
    this->ypos=ypos;
    entitySprite.setPosition(sf::Vector2f(xpos, ypos));
}

std::time_t entity::getTime(){
    return start;
}

sf::Vector2f entity::getPosition(){
    return entitySprite.getPosition();
}

void entity::refresh(){
    setSprite(path);
}

int entity::getSpawnInterval(){
    return spawnInterval;
}

void entity::setSpawnInterval(int interval){
    spawnInterval=interval;
}

bool entity::collidesWithPlayer(sf::Vector2f playerPosition){
    entityPosition=getPosition();
    return (playerPosition.x >= entityPosition.x-70 && playerPosition.x <= entityPosition.x+70 && playerPosition.y >= entityPosition.y-70 && playerPosition.y <= entityPosition.y+70);
}