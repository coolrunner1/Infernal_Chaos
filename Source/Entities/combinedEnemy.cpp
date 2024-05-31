#include "combinedEnemy.hpp"

combinedEnemy::combinedEnemy():armoredEnemy(){
    speed=4.0f;
    path="Sprites/assasin.png";
    enemyPath[0]=path;
    enemyPath[1]="Sprites/assasin_left.png";
}
