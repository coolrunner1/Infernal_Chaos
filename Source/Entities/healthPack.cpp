#include "healthPack.hpp"

healthPack::healthPack() : entity(){
    health=generateRandomInt(10, 50);
    entitySprite.setScale(3, 3);
    path="Sprites/health_pickup.png";
    setSprite(path);
}

int healthPack::getHealth(){
    return health;
}