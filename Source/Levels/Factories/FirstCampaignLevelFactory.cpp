#include "FirstCampaignLevelFactory.hpp"

std::string FirstCampaignLevelFactory::getBackground() {
    return "Sprites/lvl1_bg.png";
}

std::vector<AbstractEntityContainer*> FirstCampaignLevelFactory::getEntities() {
    std::vector<AbstractEntityContainer*> entityContainers = {
        new AmmoPacksContainer(15), 
        new ArmorPacksContainer(15), 
        new HealthPacksContainer(15), 
    };

    return entityContainers;
}

std::vector<AbstractEnemyContainer*> FirstCampaignLevelFactory::getEnemies() {
    std::vector<AbstractEnemyContainer*> enemyContainers = {
        new MobileEnemiesContainer(2), 
        new ArmoredEnemiesContainer(5),
        new CombinedEnemiesContainer(30, 0.5, 5),
    };

    return enemyContainers;
}

int FirstCampaignLevelFactory::getBossReachScore() {
    return 1000;
}

std::string FirstCampaignLevelFactory::getBossBackground() {
    return "Sprites/lvl3_bg.png";
}

int FirstCampaignLevelFactory::getNextLevelCode() {
    return 0;
}

AbstractEnemyContainer* FirstCampaignLevelFactory::getBoss() {
    return new BossContainer(1, 4);
}