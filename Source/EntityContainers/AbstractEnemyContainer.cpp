#include "AbstractEnemyContainer.hpp"

AbstractEnemyContainer::AbstractEnemyContainer(std::time_t start) : AbstractEntityContainer(start) {

}

std::vector<Enemy>* AbstractEnemyContainer::getEntities() {
    return &entities;
}

void AbstractEnemyContainer::collides(sf::RenderWindow& window, Player& player) {
    std::cerr << "This entity requires enemyBullets argument!" << std::endl;
    exit(1);
}
