#include "aliveEntity.hpp"

aliveEntity::aliveEntity():entity(){
    health=100;
    armor=100;
    speed=0.5f;
}


aliveEntity::aliveEntity(int health, int armor) : entity(xpos, ypos, path){
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
}