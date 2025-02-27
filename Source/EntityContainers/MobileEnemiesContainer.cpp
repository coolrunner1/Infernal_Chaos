#include "MobileEnemiesContainer.hpp"

MobileEnemiesContainer::MobileEnemiesContainer(std::time_t start) : AbstractEntityContainer(start){
    setLastSpawnedTimestamp(start);
}

MobileEnemiesContainer::~MobileEnemiesContainer() {
    mobileEnemies.clear();
}

void MobileEnemiesContainer::spawnNewEntity(sf::RenderWindow& window, time_t& current) {
    if (std::difftime(current, getLastSpawnedTimestamp()) > getSpawnInterval()){
        mobileEnemies.push_back(EnemyMobile());
        time_t spawnTime = mobileEnemies.back().getSpawnTime();
        setLastSpawnedTimestamp(spawnTime);
    }
}

std::vector<EnemyMobile>* MobileEnemiesContainer::getMobileEnemies() {
    return &mobileEnemies;
}

void MobileEnemiesContainer::collides(sf::RenderWindow& window, Player& player, time_t& current){
    time_t prevDamage;
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=mobileEnemies.begin(); it!=mobileEnemies.end(); ++it){
        it->enemyMove(window, playerPosition);
        it->entityDraw(window);
        if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime()) > 0.05){
            it->setDamageTime(std::time(&prevDamage));
            player.healthDamage(it->getDamage());
        }   
    }  
}