#include "ammoPack.hpp"

ammoPack::ammoPack():pickup(){
    ammo=generateRandomInt(10, 200);
    setSprite("Sprites/rascal_right.png");
    entitySprite.setScale(3, 3);
}

ammoPack::ammoPack(int ammo):pickup(xpos, ypos){
    this->ammo=ammo;
    setSprite("Sprites/rascal_right.png");
    entitySprite.setScale(3, 3);
}



/*aliveEntity::aliveEntity(int health, int armor) : entity(xpos, ypos, path){
    this->health=health;
    this->armor=armor;
    this->speed=speed;
}

void aliveEntity::healthDamage(int damage){
    if (armor>=damage){
        armor-=damage;
    }
    else {
        armor-=damage;
        health+=armor;
        armor=0;
    }
    if (health<0){
        //death animation
    }
}*/