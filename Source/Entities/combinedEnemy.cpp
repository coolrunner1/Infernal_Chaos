#include "combinedEnemy.hpp"

combinedEnemy::combinedEnemy():armoredEnemy(){
    speed=0.5f;
    path="Sprites/assasin.png";
    enemyPath[0]=path;
    enemyPath[1]="Sprites/assasin_left.png";
    entitySprite.setScale(4, 4);
    damage=25;
    armor=200;
    //setSprite("Sprites/assasin_left.png");
}

std::time_t combinedEnemy::setHighSpeed(){
    speed=4.0f;
    time(&transition);
    return transition;
}

std::time_t combinedEnemy::setLowSpeed(){
    speed=0.5f;
    time(&transition);
    return transition;
}