#include "LevelConfigurator.hpp"

MainLevel* LevelConfigurator::getPerpetualLevel(AbstractPerpetualLevelFactory& factory) {
    std::vector<AbstractEntityContainer*> entities = factory.getEntities();
    std::vector<AbstractEnemyContainer*> enemies = factory.getEnemies();

    return new MainLevel(
        factory.getBackground(),
        entities,
        enemies
    );
}

MainLevel* LevelConfigurator::getCampaignLevel(AbstractCampaignLevelFactory& factory) {
    std::vector<AbstractEntityContainer*> entities = factory.getEntities();
    std::vector<AbstractEnemyContainer*> enemies = factory.getEnemies();
    return new MainLevel(
        factory.getBackground(),
        entities,
        enemies,
        factory.getBossReachScore(),
        factory.getBossBackground(),
        factory.getNextLevelCode(),
        factory.getBoss()
    );
}