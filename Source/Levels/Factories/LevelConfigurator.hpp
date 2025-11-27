#ifndef LEVEL_CONFIGURATOR
#define LEVEL_CONFIGURATOR
#include "../MainLevel.hpp"
#include "AbstractPerpetualLevelFactory.hpp"
#include "AbstractCampaignLevelFactory.hpp"

class LevelConfigurator {
    public:
        MainLevel* getPerpetualLevel(AbstractPerpetualLevelFactory& factory);
        MainLevel* getCampaignLevel(AbstractCampaignLevelFactory& factory);
};

#endif