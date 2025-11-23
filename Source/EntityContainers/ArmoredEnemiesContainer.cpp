#include "ArmoredEnemiesContainer.hpp"

ArmoredEnemiesContainer::ArmoredEnemiesContainer() : AbstractEnemyContainer() {

}

ArmoredEnemiesContainer::~ArmoredEnemiesContainer() {
    enemies.clear();
}

void ArmoredEnemiesContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (std::difftime(std::time(nullptr), getLastSpawnedTimestamp()) > getSpawnInterval()){
        enemies.push_back(ArmoredEnemy());
        time_t spawnTime = enemies.back().getSpawnTime();
        setLastSpawnedTimestamp(spawnTime);
    }
}

void ArmoredEnemiesContainer::collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets){
    time_t prevDamage;
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=enemies.begin(); it!=enemies.end(); ++it){
        it->enemyMove(window, playerPosition);
        it->entityDraw(window);
        it->fireABullet(enemyBullets, window, playerPosition);
        if (it->collidesWithPlayer(playerPosition) && std::difftime(std::time(nullptr), it->getDamageTime()) > DAMAGE_INTERVAL){
            it->setDamageTime(std::time(&prevDamage));
            player.healthDamage(it->getDamage());
        }   
    }  
}

void ArmoredEnemiesContainer::checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player) {
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

int ArmoredEnemiesContainer::getContainerLength() {
    return enemies.size();
}

void ArmoredEnemiesContainer::clear() {
    enemies.clear();
}