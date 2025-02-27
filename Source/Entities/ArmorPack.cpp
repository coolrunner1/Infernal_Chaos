#include "ArmorPack.hpp"

ArmorPack::ArmorPack() : Entity() {
    armor = generateRandomInt(10, 50);
    entitySprite.setScale(3, 3);
    path = "Sprites/armor_pickup.png";
    setSprite(path);
    spawnInterval = 30;
}

int ArmorPack::getArmor() {
    return armor;
}
