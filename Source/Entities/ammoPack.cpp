#include "ammoPack.hpp"

ammoPack::ammoPack():entity()/*pickup()*/{
    ammo=generateRandomInt(10, 200);
    setSprite("Sprites/rascal_right.png");
    entitySprite.setScale(3, 3);
}

/*ammoPack::ammoPack(int ammo):pickup(xpos, ypos){
    this->ammo=ammo;
    setSprite("Sprites/rascal_right.png");
    entitySprite.setScale(3, 3);
}*/