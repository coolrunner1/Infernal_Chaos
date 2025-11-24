#include "BossContainer.hpp"

BossContainer::BossContainer(float assasinTransitionToSlowInterval, float assasinTransitionToFastInterval) : AbstractEnemyContainer() {
    this->assasinTransitionToSlowInterval = assasinTransitionToSlowInterval;
    this->assasinTransitionToFastInterval = assasinTransitionToFastInterval;
    defeated = false;
    boss = nullptr;
}

BossContainer::~BossContainer() {
    if (boss) delete boss;
}

void BossContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (!boss) {
        boss = new Boss();
    }
}

void BossContainer::collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets){
    if (!boss || defeated) return;
    time_t prevDamage;
    time_t current = std::time(nullptr);
    sf::Vector2f playerPosition = player.getPosition();
    if (std::difftime(current, boss->getTransitionToSlowTimestamp()) > assasinTransitionToSlowInterval){
        boss->setLowSpeed();
        boss->updateTransitionToSlowTimestamp();
    }
    if (std::difftime(current, boss->getTransitionToFastTimestamp()) > assasinTransitionToFastInterval){
        boss->setHighSpeed();
        boss->updateTransitionToFastTimestamp();
    }
    boss->enemyMove(window, playerPosition);
    boss->entityDraw(window);
    boss->fireABullet(enemyBullets, window, playerPosition);
    if (boss->collidesWithPlayer(playerPosition) && std::difftime(current, boss->getDamageTime()) > DAMAGE_INTERVAL){
        boss->setDamageTime(std::time(&prevDamage));
        player.healthDamage(boss->getDamage());
    }     
}

void BossContainer::checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player) {
    if (!boss || defeated) return;
    if (boss->collidesWithPlayer(bulletPosition)){
        boss->healthDamage(shootingDamage);
        if (boss->getHealth() <= 0){
            defeated = true;
            player.scoreIncrease(bonusScore);
        }
    }
}

int BossContainer::getContainerLength() {
    if (boss && !defeated) {
        return 1;
    }
    return 0;
}

void BossContainer::clear() {
    if (boss) delete boss;
}