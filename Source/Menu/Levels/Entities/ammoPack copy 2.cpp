#include "ammoPack.hpp"

ammoPack::ammoPack():entity(){
    xpos=generateRandomFloat(COLLISION_LEFT, COLLISION_RIGHT);
    ypos=generateRandomFloat(COLLISION_TOP, COLLISION_BOTTOM);
    ammo=0;
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