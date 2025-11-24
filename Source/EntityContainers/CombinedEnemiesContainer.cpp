#include "CombinedEnemiesContainer.hpp"

CombinedEnemiesContainer::CombinedEnemiesContainer(float spawnInterval, float assasinTransitionToSlowInterval, float assasinTransitionToFastInterval) : AbstractEnemyContainer(spawnInterval) {
    this->assasinTransitionToSlowInterval = assasinTransitionToSlowInterval;
    this->assasinTransitionToFastInterval = assasinTransitionToFastInterval;
}

CombinedEnemiesContainer::~CombinedEnemiesContainer() {
    enemies.clear();
}

void CombinedEnemiesContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (std::difftime(std::time(nullptr), getLastSpawnedTimestamp()) > getSpawnInterval()){
        enemies.push_back(CombinedEnemy(assasinTransitionToSlowInterval, assasinTransitionToFastInterval));
        time_t spawnTime = enemies.back().getSpawnTime();
        setLastSpawnedTimestamp(spawnTime);
    }
}

void CombinedEnemiesContainer::update(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets){
    time_t current = std::time(nullptr);
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=enemies.begin(); it!=enemies.end(); ++it){
        it->enemyMove(window, playerPosition);
        it->entityDraw(window);
        it->fireABullet(enemyBullets, window, playerPosition);
        int damage = it->getDamageFromCollisionWithPlayer(window, playerPosition);
        if (damage) player.healthDamage(damage); 
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

int CombinedEnemiesContainer::getContainerLength() {
    return enemies.size();
}

void CombinedEnemiesContainer::clear() {
    enemies.clear();
}