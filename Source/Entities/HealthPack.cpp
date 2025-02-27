#include "HealthPack.hpp"

HealthPack::HealthPack() : Entity() {
    health = generateRandomInt(10, 50);
    entitySprite.setScale(3, 3);
    path = "Sprites/health_pickup.png";
    setSprite(path);
}

int HealthPack::getHealth(){
    return health;
}