#include "enemyMobile.hpp"

enemyMobile::enemyMobile() : enemy(){
    //setSprite("Sprites/rascal_right.png");
    speed=0.4f;
    damage=2;
    health=75;
    armor=0;
    enemyPath[0]="Sprites/rascal_right.png";
    enemyPath[1]="Sprites/rascal.png";
}