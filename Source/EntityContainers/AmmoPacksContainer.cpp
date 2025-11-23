#include "AmmoPacksContainer.hpp"

AmmoPacksContainer::AmmoPacksContainer(std::time_t start) : AbstractEntityContainer(start) {

}

AmmoPacksContainer::~AmmoPacksContainer() {
    ammoPacks.clear();
}

void AmmoPacksContainer::collides(sf::RenderWindow& window, Player& player) {
    sf::Vector2f playerPosition = player.getPosition();
    for (auto it=ammoPacks.begin(); it!=ammoPacks.end(); ++it){
        it->refresh();
        it->entityDraw(window);
        if (it->collidesWithPlayer(playerPosition)){
                player.ammoIncrease(it->getAmmo());
                ammoPacks.erase(it);
                player.scoreIncrease(5);
                break;
        }
    }
}

void AmmoPacksContainer::spawnNewEntity(sf::RenderWindow& window) {
    if (std::difftime(std::time(nullptr), getLastSpawnedTimestamp()) > getSpawnInterval() + 15){
        ammoPacks.push_back(AmmoPack());
        ammoPacks.back().refresh();
        time_t timestamp = ammoPacks.back().getSpawnTime();
        setLastSpawnedTimestamp(timestamp);
    }
}

std::vector<AmmoPack>* AmmoPacksContainer::getAmmoPacks() {
    return &ammoPacks;
}