#include "armorPack.hpp"

armorPack::armorPack() : entity(){
    armor=generateRandomInt(10, 50);
    entitySprite.setScale(3, 3);
    path="Sprites/armor_pickup.png";
    setSprite(path);
    spawnInterval=30;
}

int armorPack::getArmor(){
    return armor;
}
