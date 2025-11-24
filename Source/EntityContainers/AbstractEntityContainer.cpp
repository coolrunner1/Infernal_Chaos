#include "AbstractEntityContainer.hpp"

AbstractEntityContainer::AbstractEntityContainer() {
    lastSpawnedTimestamp = std::time(nullptr);
    this->spawnInterval = 15;
}

AbstractEntityContainer::AbstractEntityContainer(float spawnInterval) {
    lastSpawnedTimestamp = std::time(nullptr);
    this->spawnInterval = spawnInterval;
}

AbstractEntityContainer::~AbstractEntityContainer() {
    
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