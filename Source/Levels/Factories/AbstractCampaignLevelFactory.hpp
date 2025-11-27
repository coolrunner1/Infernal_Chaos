#ifndef ABSTRACT_CAMPAIGN_LEVEL_FACTORY
#define ABSTRACT_CAMPAIGN_LEVEL_FACTORY
#include "AbstractPerpetualLevelFactory.hpp"

class AbstractCampaignLevelFactory : public AbstractPerpetualLevelFactory {
    public:
        virtual int getBossReachScore() = 0;
        virtual std::string getBossBackground() = 0;
        virtual int getNextLevelCode() = 0;
        virtual AbstractEnemyContainer* getBoss() = 0;
};

#endif