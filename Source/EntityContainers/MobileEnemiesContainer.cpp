#include "MobileEnemiesContainer.hpp"

MobileEnemiesContainer::MobileEnemiesContainer(float spawnInterval) : AbstractEnemyContainer(spawnInterval) {

}

MobileEnemiesContainer::~MobileEnemiesContainer() {
    enemies.clear();
}

void MobileEnemiesContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (std::difftime(std::time(nullptr), getLastSpawnedTimestamp()) > getSpawnInterval()){
        enemies.push_back(EnemyMobile());
        time_t spawnTime = enemies.back().getSpawnTime();
        setLastSpawnedTimestamp(spawnTime);
    }
}

void MobileEnemiesContainer::checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player) {
    for (auto it = enemies.begin(); it != enemies.end(); ++it){
        if (it->collidesWithPlayer(bulletPosition)){
            it->healthDamage(shootingDamage);
            if (it->getHealth() <= 0){
                enemies.erase(it);
                player.scoreIncrease(bonusScore);
                break;
            }
        }
    }
}

void MobileEnemiesContainer::update(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets) {
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=enemies.begin(); it!=enemies.end(); ++it){
        it->enemyMove(window, playerPosition);
        it->entityDraw(window);
        int damage = it->getDamageFromCollisionWithPlayer(window, playerPosition);
        if (damage) player.healthDamage(damage); 
    }  
}

int MobileEnemiesContainer::getContainerLength() {
    return enemies.size();
}

void MobileEnemiesContainer::clear() {
    enemies.clear();
}
