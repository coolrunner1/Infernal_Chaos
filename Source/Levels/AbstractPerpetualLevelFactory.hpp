#ifndef ABSTRACT_PERPETUAL_LEVEL_FACTORY
#define ABSTRACT_PERPETUAL_LEVEL_FACTORY
#include "../EntityContainers/AbstractEntityContainer.hpp"
#include "../EntityContainers/AbstractEnemyContainer.hpp"

class AbstractPerpetualLevelFactory {
    public:
        virtual std::string getBackground() = 0;
        virtual std::vector<AbstractEnemyContainer*>& getEntities() = 0;
        virtual std::vector<AbstractEnemyContainer*>& getEnemies() = 0;
};

#endif