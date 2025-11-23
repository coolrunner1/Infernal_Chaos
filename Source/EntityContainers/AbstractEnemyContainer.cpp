#include "AbstractEnemyContainer.hpp"

AbstractEnemyContainer::AbstractEnemyContainer() : AbstractEntityContainer() {

}

void AbstractEnemyContainer::collides(sf::RenderWindow& window, Player& player) {
    std::cerr << "This entity requires enemyBullets argument!" << std::endl;
    exit(1);
}