#include "MobileEnemiesContainer.hpp"

MobileEnemiesContainer::MobileEnemiesContainer(std::time_t start) : AbstractEntityContainer(start) {

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

std::vector<EnemyMobile>& MobileEnemiesContainer::getEntities() {
    return enemies;
}

void MobileEnemiesContainer::collides(sf::RenderWindow& window, Player& player) {
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