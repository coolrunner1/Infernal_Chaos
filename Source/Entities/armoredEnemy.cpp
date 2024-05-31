#include "armoredEnemy.hpp"

armoredEnemy::armoredEnemy(){
    setSprite("Sprites/robot.png");
    enemyPath[0]="Sprites/robot.png";
    enemyPath[1]="Sprites/robot_left.png";
    health=125;
    entitySprite.setScale(4, 4);
}

void armoredEnemy::setFired(std::time_t fired){
    lastFired=fired;
}

std::time_t armoredEnemy::getLastFired(){
    return lastFired;
}