#include "MediumPerpetualLevelFactory.hpp"

std::string MediumPerpetualLevelFactory::getBackground() {
    return "Sprites/lvl1_bg.png";
}

std::vector<AbstractEntityContainer*> MediumPerpetualLevelFactory::getEntities() {
    std::vector<AbstractEntityContainer*> entityContainers = {
        new AmmoPacksContainer(25), 
        new ArmorPacksContainer(25), 
        new HealthPacksContainer(25), 
    };

    return entityContainers;
}

std::vector<AbstractEnemyContainer*> MediumPerpetualLevelFactory::getEnemies() {
    std::vector<AbstractEnemyContainer*> enemyContainers = {
        new MobileEnemiesContainer(1),  
        new ArmoredEnemiesContainer(5),
        new CombinedEnemiesContainer(15, 0.7, 3),
    };

    return enemyContainers;
}