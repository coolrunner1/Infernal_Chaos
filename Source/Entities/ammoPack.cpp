#include "ammoPack.hpp"

ammoPack::ammoPack():entity(){
    ammo=generateRandomInt(10, 75);
    entitySprite.setScale(3, 3);
    path="Sprites/ammo_pickup.png";
    setSprite(path);
}

int ammoPack::getAmmo(){
    return ammo;
}
