#include "healthPack.hpp"

healthPack::healthPack() : entity()/*pickup()*/{
    health=generateRandomInt(10, 50);
    entitySprite.setScale(3, 3);
    path="Sprites/health_pickup.png";
    setSprite(path);
}

int healthPack::getHealth(){
    return health;
}

/*ammoPack::ammoPack(int ammo):pickup(xpos, ypos){
    this->ammo=ammo;
    setSprite("Sprites/rascal_right.png");
    entitySprite.setScale(3, 3);
}*/