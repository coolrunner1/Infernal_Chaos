#ifndef MEDIUM_PERPETUAL_LEVEL_FACTORY
#define MEDIUM_PERPETUAL_LEVEL_FACTORY
#include "AbstractPerpetualLevelFactory.hpp"
#include "../../EntityContainers/AmmoPacksContainer.hpp"
#include "../../EntityContainers/ArmorPacksContainer.hpp"
#include "../../EntityContainers/HealthPacksContainer.hpp"
#include "../../EntityContainers/MobileEnemiesContainer.hpp"
#include "../../EntityContainers/ArmoredEnemiesContainer.hpp"
#include "../../EntityContainers/CombinedEnemiesContainer.hpp"

class MediumPerpetualLevelFactory : public AbstractPerpetualLevelFactory {
    public:
        std::string getBackground();
        std::vector<AbstractEntityContainer*> getEntities();
        std::vector<AbstractEnemyContainer*> getEnemies();
};

#endif