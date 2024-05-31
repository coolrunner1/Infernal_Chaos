#include "armorPack.hpp"

armorPack::armorPack():entity()/*pickup()*/{
    armor=generateRandomInt(10, 50);
    entitySprite.setScale(3, 3);
    path="Sprites/armor_pickup.png";
    setSprite(path);
    //std::cout<<"ammopack";
}

int armorPack::getArmor(){
    return armor;
}

/*ammoPack::ammoPack(int ammo):pickup(xpos, ypos){
    this->ammo=ammo;
    setSprite("Sprites/rascal_right.png");
    entitySprite.setScale(3, 3);
}*/