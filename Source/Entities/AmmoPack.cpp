#include "AmmoPack.hpp"

AmmoPack::AmmoPack() : Entity() {
    ammo = generateRandomInt(10, 75);
    entitySprite.setScale(3, 3);
    path = "Sprites/ammo_pickup.png";
    setSprite(path);
}

int AmmoPack::getAmmo() {
    return ammo;
}
