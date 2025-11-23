#include "AbstractEntityContainer.hpp"

AbstractEntityContainer::AbstractEntityContainer(std::time_t start) {
    setLastSpawnedTimestamp(start);
}

time_t AbstractEntityContainer::getLastSpawnedTimestamp() {
    return lastSpawnedTimestamp;
}

void AbstractEntityContainer::setLastSpawnedTimestamp(std::time_t& timestamp) {
    lastSpawnedTimestamp = timestamp;
}

void AbstractEntityContainer::setSpawnInterval(float spawnInterval) {
    this->spawnInterval = spawnInterval;
}

float AbstractEntityContainer::getSpawnInterval() {
    return spawnInterval;
}

std::vector<Entity>& AbstractEntityContainer::getEntities() {
    return entities;
}
