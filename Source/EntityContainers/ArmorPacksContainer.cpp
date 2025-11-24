#include "ArmorPacksContainer.hpp"

ArmorPacksContainer::ArmorPacksContainer(float spawnInterval) : AbstractEntityContainer(spawnInterval) {
    setBonusScore(5);
}

ArmorPacksContainer::~ArmorPacksContainer() {
    armorPacks.clear();
}

void ArmorPacksContainer::update(sf::RenderWindow& window, Player& player) {
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=armorPacks.begin(); it!=armorPacks.end(); ++it){
        it->refreshSprite();
        it->entityDraw(window);
        if (it->collidesWithPlayer(playerPosition)){
                player.armorIncrease(it->getArmor());
                armorPacks.erase(it);
                player.scoreIncrease(getBonusScore());
                break;
        }
    }
}

void ArmorPacksContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (std::difftime(std::time(nullptr), getLastSpawnedTimestamp()) > getSpawnInterval() + 25){
        armorPacks.push_back(ArmorPack());
        armorPacks.back().refreshSprite();
        time_t timestamp = armorPacks.back().getSpawnTime();
        setLastSpawnedTimestamp(timestamp);
    }
}

int ArmorPacksContainer::getContainerLength() {
    return armorPacks.size();
}

void ArmorPacksContainer::clear() {
    armorPacks.clear();
}