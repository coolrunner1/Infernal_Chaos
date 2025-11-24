#include "NullEnemiesContainer.hpp"

NullEnemiesContainer::NullEnemiesContainer() : AbstractEnemyContainer() {

}

NullEnemiesContainer::~NullEnemiesContainer() {

}

void NullEnemiesContainer::spawnNewEntity(sf::RenderWindow& window) {

}

void NullEnemiesContainer::update(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets){
 
}

void NullEnemiesContainer::checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, Player& player) {
    
}

int NullEnemiesContainer::getContainerLength() {
    return 0;
}

void NullEnemiesContainer::clear() {

}