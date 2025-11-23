#include "NullEnemiesContainer.hpp"

NullEnemiesContainer::NullEnemiesContainer() : AbstractEnemyContainer() {

}

NullEnemiesContainer::~NullEnemiesContainer() {

}

void NullEnemiesContainer::spawnNewEntity(sf::RenderWindow& window) {

}

void NullEnemiesContainer::collides(sf::RenderWindow& window, Player& player){
 
}

void NullEnemiesContainer::collides(sf::RenderWindow& window, Player& player, std::vector<Bullet>& enemyBullets){
 
}

void NullEnemiesContainer::checkCollisionWithPlayersBullet(sf::Vector2f bulletPosition, int shootingDamage, int bonusScore, Player& player) {
    
}