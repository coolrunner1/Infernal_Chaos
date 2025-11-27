#include "EasyPerpetualLevelFactory.hpp"

std::string EasyPerpetualLevelFactory::getBackground() {
    return "Sprites/lvl3_bg.png";
}

std::vector<AbstractEntityContainer*> EasyPerpetualLevelFactory::getEntities() {
    std::vector<AbstractEntityContainer*> entityContainers = {
        new AmmoPacksContainer(15), 
        new ArmorPacksContainer(15), 
        new HealthPacksContainer(15), 
    };

    return entityContainers;
}

std::vector<AbstractEnemyContainer*> EasyPerpetualLevelFactory::getEnemies() {
    std::vector<AbstractEnemyContainer*> enemyContainers = {
        new MobileEnemiesContainer(2), 
        new ArmoredEnemiesContainer(5),
    };

    return enemyContainers;
}