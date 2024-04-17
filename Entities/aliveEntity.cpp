#include "aliveEntity.hpp"

aliveEntity::aliveEntity():entity(){
    health=100;
    armor=100;
}


aliveEntity::aliveEntity(int health, int armor) : entity(xpos, ypos){
    this->health=100;
    this->armor=100;
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
}