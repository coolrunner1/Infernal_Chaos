#include "EnemyMobile.hpp"

EnemyMobile::EnemyMobile() : Enemy(){
    enemyMobileInit();
}

EnemyMobile::EnemyMobile(bool rascal) : Enemy(){
    if (rascal)
        enemyMobileInit();
}

void EnemyMobile::enemyMobileInit(){
    speed=0.4f;
    damage=2;
    health=75;
    armor=0;
    enemyPath[0]="Sprites/rascal_right.png";
    enemyPath[1]="Sprites/rascal.png";
}