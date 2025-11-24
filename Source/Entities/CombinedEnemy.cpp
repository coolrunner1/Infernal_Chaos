#include "CombinedEnemy.hpp"

CombinedEnemy::CombinedEnemy(float transitionToSlowInterval, float transitionToFastInterval) : ArmoredEnemy(false) {
    speed = 0.5f;
    entitySprite.setScale(4, 4);
    this->transitionToSlowInterval = transitionToSlowInterval;
    this->transitionToFastInterval = transitionToFastInterval;
    combinedEnemyInit();
}

CombinedEnemy::CombinedEnemy(float transitionToSlowInterval, float transitionToFastInterval, bool assasin) : ArmoredEnemy(false) {
    speed = 0.5f;
    entitySprite.setScale(4, 4);
    this->transitionToSlowInterval = transitionToSlowInterval;
    this->transitionToFastInterval = transitionToFastInterval;
    if (assasin) {
        combinedEnemyInit();
    }
}

void CombinedEnemy::enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos) {
    time_t current = std::time(nullptr);

    if (std::difftime(current, getTransitionToSlowTimestamp()) > transitionToSlowInterval){
        setLowSpeed();
        updateTransitionToSlowTimestamp();
    }
    if (std::difftime(current, getTransitionToFastTimestamp()) > transitionToFastInterval){
        setHighSpeed();
        updateTransitionToFastTimestamp();
    }

    Enemy::enemyMove(window, playerPos);
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