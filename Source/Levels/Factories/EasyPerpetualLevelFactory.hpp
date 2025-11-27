#ifndef EASY_PERPETUAL_LEVEL_FACTORY
#define EASY_PERPETUAL_LEVEL_FACTORY
#include "AbstractPerpetualLevelFactory.hpp"
#include "../../EntityContainers/AmmoPacksContainer.hpp"
#include "../../EntityContainers/ArmorPacksContainer.hpp"
#include "../../EntityContainers/HealthPacksContainer.hpp"
#include "../../EntityContainers/MobileEnemiesContainer.hpp"
#include "../../EntityContainers/ArmoredEnemiesContainer.hpp"

class EasyPerpetualLevelFactory : public AbstractPerpetualLevelFactory {
    public:
        std::string getBackground();
        std::vector<AbstractEntityContainer*> getEntities();
        std::vector<AbstractEnemyContainer*> getEnemies();
};

#endif