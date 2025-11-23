#include "Boss.hpp"

Boss::Boss() : CombinedEnemy(false) {
    path = "Sprites/zombie.png";
    enemyPath[0] = path;
    enemyPath[1] = "Sprites/zombie_left.png";
    damage = 50;
    health = 500;
    armor = 500;
    lastFired = transitionToSlowTimestamp = transitionToFastTimestamp = std::time(nullptr);
    setFireInterval(4);
}