#include "NullEntitiesContainer.hpp"

NullEntitiesContainer::NullEntitiesContainer() : AbstractEntityContainer() {

}

NullEntitiesContainer::~NullEntitiesContainer() {

}

void NullEntitiesContainer::collides(sf::RenderWindow& window, Player& player) {
    
}

void NullEntitiesContainer::spawnNewEntity(sf::RenderWindow& window) {
    
}

int NullEntitiesContainer::getContainerLength() {
    return 0;
}

void NullEntitiesContainer::clear() {

}