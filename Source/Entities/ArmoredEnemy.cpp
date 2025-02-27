#include "ArmoredEnemy.hpp"

ArmoredEnemy::ArmoredEnemy() {
    armoredInit();
}

ArmoredEnemy::ArmoredEnemy(bool robot) {
    if (robot) {
        armoredInit();
    }
}

void ArmoredEnemy::armoredInit() {
    setSprite("Sprites/robot.png");
    enemyPath[0] = "Sprites/robot.png";
    enemyPath[1] = "Sprites/robot_left.png";
    health = 125;
    entitySprite.setScale(4, 4);
}

void ArmoredEnemy::setFired(std::time_t fired) {
    lastFired = fired;
}

std::time_t ArmoredEnemy::getLastFired() {
    return lastFired;
}