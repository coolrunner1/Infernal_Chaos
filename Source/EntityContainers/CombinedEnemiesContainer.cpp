#include "CombinedEnemiesContainer.hpp"

CombinedEnemiesContainer::CombinedEnemiesContainer(float assasinTransitionToSlowInterval, float assasinTransitionToFastInterval) : AbstractEnemyContainer() {
    this->assasinTransitionToSlowInterval = assasinTransitionToSlowInterval;
    this->assasinTransitionToFastInterval = assasinTransitionToFastInterval;
}

CombinedEnemiesContainer::~CombinedEnemiesContainer() {
    enemies.clear();
}

void CombinedEnemiesContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (std::difftime(std::time(nullptr), getLastSpawnedTimestamp()) > getSpawnInterval()){
        enemies.push_back(CombinedEnemy());
        time_t spawnTime = enemies.back().getSpawnTime();
        setLastSpawnedTimestamp(spawnTime);
    }
}

void CombinedEnemiesContainer::collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets){
    time_t prevDamage;
    time_t current = std::time(nullptr);
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=enemies.begin(); it!=enemies.end(); ++it){
        if (std::difftime(current, it->getTransitionToSlowTimestamp()) > assasinTransitionToSlowInterval){
            it->setLowSpeed();
            it->updateTransitionToSlowTimestamp();
        }
        if (std::difftime(current, it->getTransitionToFastTimestamp()) > assasinTransitionToFastInterval){
            it->setHighSpeed();
            it->updateTransitionToFastTimestamp();
        }
        it->enemyMove(window, playerPosition);
        it->entityDraw(window);
        it->fireABullet(enemyBullets, window, playerPosition);
        if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime()) > DAMAGE_INTERVAL){
            it->setDamageTime(std::time(&prevDamage));
            player.healthDamage(it->getDamage());
        }   
    }  
}

void CombinedEnemiesContainer::checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player) {
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