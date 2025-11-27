#ifndef FIRST_CAMPAIGN_LEVEL_FACTORY
#define FIRST_CAMPAIGN_LEVEL_FACTORY
#include "AbstractCampaignLevelFactory.hpp"
#include "../../EntityContainers/AmmoPacksContainer.hpp"
#include "../../EntityContainers/ArmorPacksContainer.hpp"
#include "../../EntityContainers/HealthPacksContainer.hpp"
#include "../../EntityContainers/MobileEnemiesContainer.hpp"
#include "../../EntityContainers/ArmoredEnemiesContainer.hpp"
#include "../../EntityContainers/CombinedEnemiesContainer.hpp"
#include "../../EntityContainers/BossContainer.hpp"

class FirstCampaignLevelFactory : public AbstractCampaignLevelFactory {
    public:
        std::string getBackground();
        std::vector<AbstractEntityContainer*> getEntities();
        std::vector<AbstractEnemyContainer*> getEnemies();
        int getBossReachScore();
        std::string getBossBackground();
        int getNextLevelCode();
        AbstractEnemyContainer* getBoss();
};

#endif