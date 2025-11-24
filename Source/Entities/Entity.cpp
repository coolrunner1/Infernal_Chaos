#include "Entity.hpp"

Entity::Entity() {
    xpos = generateRandomFloat(COLLISION_LEFT, COLLISION_RIGHT);
    ypos = generateRandomFloat(COLLISION_TOP, COLLISION_BOTTOM);
    entityInit();
}

void Entity::entityDraw(sf::RenderWindow& window) {
    window.draw(entitySprite);
}

Entity::Entity(int xpos, int ypos, std::string path) {
    this->xpos = xpos;
    this->ypos = ypos;
    this->path = path;
    setSprite(path);
    entityInit();
}

void Entity::setSprite(std::string path) {
    if (!entityTexture.loadFromFile(path)) {
        std::cerr << "Missing file: "<< path << std::endl;
    }
    entitySprite.setTexture(entityTexture);
}

void Entity::entityInit() {
    std::time(&start);
    entitySprite.setPosition(sf::Vector2f(xpos, ypos));
}

void Entity::entityMove(int xpos, int ypos) {
    this->xpos = xpos;
    this->ypos = ypos;
    entitySprite.setPosition(sf::Vector2f(xpos, ypos));
}

std::time_t Entity::getSpawnTime() {
    return start;
}

sf::Vector2f Entity::getPosition() {
    return entitySprite.getPosition();
}

void Entity::refreshSprite() {
    setSprite(path);
}

int Entity::getSpawnInterval() {
    return spawnInterval;
}

void Entity::setSpawnInterval(int interval) {
    spawnInterval = interval;
}

bool Entity::collidesWithPlayer(sf::Vector2f playerPosition) {
    entityPosition=getPosition();
    return (playerPosition.x >= entityPosition.x-70 && playerPosition.x <= entityPosition.x+70 
        && playerPosition.y >= entityPosition.y-70 && playerPosition.y <= entityPosition.y+70);
}