#include "AbstractEntityContainer.hpp"

AbstractEntityContainer::AbstractEntityContainer(std::time_t start){
    setLastSpawnedTimestamp(start);
}

time_t AbstractEntityContainer::getLastSpawnedTimestamp(){
    return lastSpawnedTimestamp;
}

void AbstractEntityContainer::setLastSpawnedTimestamp(std::time_t& timestamp){
    lastSpawnedTimestamp = timestamp;
}

void AbstractEntityContainer::collides(sf::RenderWindow& window, Player& player, time_t& current){
    std::cerr << "Warning: \"collides\" method is not implemented!" << std::endl;
}

void AbstractEntityContainer::setSpawnInterval(float spawnInterval) {
    this->spawnInterval = spawnInterval;
}

float AbstractEntityContainer::getSpawnInterval() {
    return spawnInterval;
}

void AbstractEntityContainer::spawnNewEntity(sf::RenderWindow& window, time_t& current) {
    std::cerr << "Warning: \"spawnNewEntity\" method is not implemented!" << std::endl;
}

