#include "AbstractEntityContainer.hpp"

AbstractEntityContainer::AbstractEntityContainer() {
    lastSpawnedTimestamp = std::time(nullptr);
    this->spawnInterval = 15;
    bonusScore = 0;
}

AbstractEntityContainer::AbstractEntityContainer(float spawnInterval) {
    lastSpawnedTimestamp = std::time(nullptr);
    this->spawnInterval = spawnInterval;
    bonusScore = 0;
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

int AbstractEntityContainer::getBonusScore() {
    return bonusScore;
}

void AbstractEntityContainer::setBonusScore(int bonusScore) {
    this->bonusScore = bonusScore;
}