#include "ArmoredEnemiesContainer.hpp"

ArmoredEnemiesContainer::ArmoredEnemiesContainer(std::time_t start) : AbstractEnemyContainer(start) {

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

std::vector<ArmoredEnemy>& ArmoredEnemiesContainer::getEntities() {
    return enemies;
}

void ArmoredEnemiesContainer::collides(sf::RenderWindow& window, Player& player){
    std::cerr << "You can't use this function! This enemy type must fire bullets!" << std::endl;
    exit(1);
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