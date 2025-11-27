#include "HardPerpetualLevelFactory.hpp"

std::string HardPerpetualLevelFactory::getBackground() {
    return "Sprites/lvl1_bg.png";
}

std::vector<AbstractEntityContainer*> HardPerpetualLevelFactory::getEntities() {
    std::vector<AbstractEntityContainer*> entityContainers = {
        new AmmoPacksContainer(35),
        new HealthPacksContainer(35), 
    };

    return entityContainers;
}

std::vector<AbstractEnemyContainer*> HardPerpetualLevelFactory::getEnemies() {
    std::vector<AbstractEnemyContainer*> enemyContainers = {
        new ArmoredEnemiesContainer(1),
        new CombinedEnemiesContainer(12, 0.7, 3), 
        new MobileEnemiesContainer(2), 
        new MobileEnemiesContainer(2), 
        new MobileEnemiesContainer(2),
    };

    return enemyContainers;
}