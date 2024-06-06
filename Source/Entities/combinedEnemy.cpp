#include "combinedEnemy.hpp"

combinedEnemy::combinedEnemy():armoredEnemy(false){
    speed=0.5f;
    entitySprite.setScale(4, 4);
    combinedEnemyInit();
}

combinedEnemy::combinedEnemy(bool assasin):armoredEnemy(false){
    speed=0.5f;
    entitySprite.setScale(4, 4);
    if (assasin)
        combinedEnemyInit();
}


void combinedEnemy::combinedEnemyInit(){
    path="Sprites/assasin.png";
    enemyPath[0]=path;
    enemyPath[1]="Sprites/assasin_left.png";
    damage=25;
    armor=200;
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