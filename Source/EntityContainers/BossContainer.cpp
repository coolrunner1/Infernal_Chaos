#include "BossContainer.hpp"

BossContainer::BossContainer(float assasinTransitionToSlowInterval, float assasinTransitionToFastInterval) : AbstractEnemyContainer() {
    this->assasinTransitionToSlowInterval = assasinTransitionToSlowInterval;
    this->assasinTransitionToFastInterval = assasinTransitionToFastInterval;
    defeated = false;
    boss = nullptr;
    setBonusScore(1000);
}

BossContainer::~BossContainer() {
    if (boss) delete boss;
}

void BossContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (!boss) {
        boss = new Boss(assasinTransitionToSlowInterval, assasinTransitionToFastInterval);
    }
}

void BossContainer::update(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets){
    if (!boss || defeated) return;
    sf::Vector2f playerPosition = player.getPosition();
    boss->enemyMove(window, playerPosition);
    boss->entityDraw(window);
    boss->fireABullet(enemyBullets, window, playerPosition);
    int damage = boss->getDamageFromCollisionWithPlayer(window, playerPosition);
    if (damage) player.healthDamage(damage);  
}

void BossContainer::checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, Player& player) {
    if (!boss || defeated) return;
    if (boss->collidesWithPlayer(bulletPosition)){
        boss->healthDamage(shootingDamage);
        if (boss->getHealth() <= 0){
            defeated = true;
            player.scoreIncrease(getBonusScore());
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