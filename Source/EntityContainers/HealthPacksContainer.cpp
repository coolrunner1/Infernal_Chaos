#include "HealthPacksContainer.hpp"

HealthPacksContainer::HealthPacksContainer(std::time_t start) : AbstractEntityContainer(start) {

}

HealthPacksContainer::~HealthPacksContainer() {
    healthPacks.clear();
}

void HealthPacksContainer::collides(sf::RenderWindow& window, Player& player, time_t& current) {
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=healthPacks.begin(); it!=healthPacks.end(); ++it){
        it->refresh();
        it->entityDraw(window);
        if (it->collidesWithPlayer(playerPosition)){
                player.healthIncrease(it->getHealth());
                healthPacks.erase(it);
                player.scoreIncrease(5);
                break;
        }
    }
}

void HealthPacksContainer::spawnNewEntity(sf::RenderWindow& window, time_t& current) {
    if (std::difftime(current, getLastSpawnedTimestamp()) > getSpawnInterval() + 20){
        healthPacks.push_back(HealthPack());
        healthPacks.back().refresh();
        time_t timestamp = healthPacks.back().getSpawnTime();
        setLastSpawnedTimestamp(timestamp);
}
}

std::vector<HealthPack>* HealthPacksContainer::getHealthPacks() {
    return &healthPacks;
}