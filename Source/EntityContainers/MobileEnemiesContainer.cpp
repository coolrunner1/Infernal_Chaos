#include "MobileEnemiesContainer.hpp"

MobileEnemiesContainer::MobileEnemiesContainer() : AbstractEnemyContainer() {

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
            if (it->getHealth()<=0){
                enemies.erase(it);
                player.scoreIncrease(bonusScore);
                break;
            }
        }
    }
}

void MobileEnemiesContainer::collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets) {
    time_t prevDamage;
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=enemies.begin(); it!=enemies.end(); ++it){
        it->enemyMove(window, playerPosition);
        it->entityDraw(window);
        if (it->collidesWithPlayer(playerPosition) && std::difftime(std::time(nullptr), it->getDamageTime()) > DAMAGE_INTERVAL){
            it->setDamageTime(std::time(&prevDamage));
            player.healthDamage(it->getDamage());
        }   
    }  
}

int MobileEnemiesContainer::getContainerLength() {
    return enemies.size();
}

void MobileEnemiesContainer::clear() {
    enemies.clear();
}
