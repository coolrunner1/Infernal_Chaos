#include "ArmoredEnemy.hpp"

ArmoredEnemy::ArmoredEnemy() {
    armoredInit();
}

ArmoredEnemy::ArmoredEnemy(int fireInterval) {
    armoredInit(fireInterval);
}

ArmoredEnemy::ArmoredEnemy(bool robot) {
    if (robot) {
        armoredInit();
    }
}

void ArmoredEnemy::armoredInit(int fireInterval) {
    setSprite("Sprites/robot.png");
    enemyPath[0] = "Sprites/robot.png";
    enemyPath[1] = "Sprites/robot_left.png";
    health = 125;
    entitySprite.setScale(4, 4);
    lastFired = std::time(nullptr);
    this->fireInterval = fireInterval;
}

void ArmoredEnemy::setFired(std::time_t fired) {
    lastFired = fired;
}

std::time_t ArmoredEnemy::getLastFired() {
    return lastFired;
}

void ArmoredEnemy::setFireInterval(int fireInterval) {
    this->fireInterval = fireInterval;
}

int ArmoredEnemy::getFireInterval() {
    return fireInterval;
}


void ArmoredEnemy::fireABullet(std::vector<Bullet>& bullets, sf::RenderWindow& window, sf::Vector2f playerPosition) {
    std::time_t current = std::time(nullptr);
    if (std::difftime(current, getLastFired()) > fireInterval){
        setFired(current);
        bullets.push_back(Bullet());
        bullets.back().refresh();
        bullets.back().bulletSetFloat(window, getPosition(), playerPosition);
    }
}