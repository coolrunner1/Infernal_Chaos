#include "boss.hpp"

boss::boss():combinedEnemy(false){
    path="Sprites/zombie.png";
    enemyPath[0]=path;
    enemyPath[1]="Sprites/zombie_left.png";
    damage=50;
    health=500;
    armor=500;
}