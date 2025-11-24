#include "AmmoPacksContainer.hpp"

AmmoPacksContainer::AmmoPacksContainer(float spawnInterval) : AbstractEntityContainer(spawnInterval) {
    setBonusScore(5);
}

AmmoPacksContainer::~AmmoPacksContainer() {
    ammoPacks.clear();
}

void AmmoPacksContainer::update(sf::RenderWindow& window, Player& player) {
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=ammoPacks.begin(); it!=ammoPacks.end(); ++it){
        it->refreshSprite();
        it->entityDraw(window);
        if (it->collidesWithPlayer(playerPosition)){
                player.ammoIncrease(it->getAmmo());
                ammoPacks.erase(it);
                player.scoreIncrease(getBonusScore());
                break;
        }
    }
}

void AmmoPacksContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (std::difftime(std::time(nullptr), getLastSpawnedTimestamp()) > getSpawnInterval() + 15){
        ammoPacks.push_back(AmmoPack());
        ammoPacks.back().refreshSprite();
        time_t timestamp = ammoPacks.back().getSpawnTime();
        setLastSpawnedTimestamp(timestamp);
    }
}

int AmmoPacksContainer::getContainerLength() {
    return ammoPacks.size();
}

void AmmoPacksContainer::clear() {
    ammoPacks.clear();
}