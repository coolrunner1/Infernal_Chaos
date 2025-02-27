#include "ArmorPacksContainer.hpp"

ArmorPacksContainer::ArmorPacksContainer(std::time_t start) : AbstractEntityContainer(start) {

}

ArmorPacksContainer::~ArmorPacksContainer() {
    armorPacks.clear();
}

void ArmorPacksContainer::collides(sf::RenderWindow& window, Player& player, time_t& current) {
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=armorPacks.begin(); it!=armorPacks.end(); ++it){
        it->refresh();
        it->entityDraw(window);
        if (it->collidesWithPlayer(playerPosition)){
                player.armorIncrease(it->getArmor());
                armorPacks.erase(it);
                player.scoreIncrease(5);
                break;
        }
    }
}

void ArmorPacksContainer::spawnNewEntity(sf::RenderWindow& window, time_t& current) {
    if (std::difftime(current, getLastSpawnedTimestamp()) > getSpawnInterval() + 25){
        armorPacks.push_back(ArmorPack());
        armorPacks.back().refresh();
        time_t timestamp = armorPacks.back().getSpawnTime();
        setLastSpawnedTimestamp(timestamp);
    }
}

std::vector<ArmorPack>* ArmorPacksContainer::getArmorPacks() {
    return &armorPacks;
}