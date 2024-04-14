#include "aliveEntity.h"

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

aliveEntity::aliveEntity(){
    health=100;
    armor=100;
}
