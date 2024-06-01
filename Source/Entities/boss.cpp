#include "boss.hpp"

boss::boss():combinedEnemy(path){
    speed=0.5f;
    path="Sprites/zombie.png";
    enemyPath[0]=path;
    enemyPath[1]="Sprites/zombie_left.png";
    entitySprite.setScale(4, 4);
    damage=50;
    health=200;
    armor=300;
    setSprite("Sprites/zombie_left.png");
}