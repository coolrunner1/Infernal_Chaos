#include "CombinedEnemy.hpp"

CombinedEnemy::CombinedEnemy() : ArmoredEnemy(false) {
    speed = 0.5f;
    entitySprite.setScale(4, 4);
    combinedEnemyInit();
}

CombinedEnemy::CombinedEnemy(bool assasin) : ArmoredEnemy(false) {
    speed = 0.5f;
    entitySprite.setScale(4, 4);
    if (assasin) {
        combinedEnemyInit();
    }
}

void CombinedEnemy::combinedEnemyInit() {
    path = "Sprites/assasin.png";
    enemyPath[0] = path;
    enemyPath[1] = "Sprites/assasin_left.png";
    damage = 25;
    armor = 200;
    lastFired = transitionToSlowTimestamp = transitionToFastTimestamp = std::time(nullptr);
    setFireInterval(4);
}

void CombinedEnemy::setHighSpeed() {
    speed = 4.0f;
}

void CombinedEnemy::setLowSpeed() {
    speed = 0.5f;
}

std::time_t CombinedEnemy::getTransitionToSlowTimestamp() {
    return transitionToSlowTimestamp;
}

std::time_t CombinedEnemy::getTransitionToFastTimestamp() {
    return transitionToFastTimestamp;
}


void CombinedEnemy::updateTransitionToSlowTimestamp() {
    transitionToSlowTimestamp = std::time(nullptr);
}

void CombinedEnemy::updateTransitionToFastTimestamp() {
    transitionToFastTimestamp = std::time(nullptr);
}