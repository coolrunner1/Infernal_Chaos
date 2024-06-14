#ifndef MAINLEVEL
#define MAINLEVEL
#include "levelPattern.hpp"
#include "bossContainer.hpp"
#include "armoredContainer.hpp"
#include "mobileContainer.hpp"
#include "ammoPackContainer.hpp"
#include "armorPackContainer.hpp"
#include "healthPackContainer.hpp"
#include "../Entities/enemyMobile.hpp"
#include "../Entities/bullet.hpp"
#include "../Entities/ammoPack.hpp"
#include "../Entities/armorPack.hpp"
#include "../Entities/healthPack.hpp"
#include "../Entities/armoredEnemy.hpp"
#include "../Entities/combinedEnemy.hpp"
#include "../Entities/boss.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class mainLevel : public levelPattern{
    protected:
        std::string path;
        //std::vector<armoredEnemy> armoredEnemies;
        std::vector<combinedEnemy> combinedEnemies;
        bossContainer* bossContainerPoint;
        ammoPackContainer* ammoPacksContainer;
        armorPackContainer* armorPacksContainer;
        healthPackContainer* healthPacksContainer;
        mobileContainer* mobileEnemiesContainer;
        armoredContainer* armoredEnemiesContainer;
        float assasinSpawnInterval;
        float assasinInterval[2];
        float mobileInterval;
        float armoredInterval;
        std::time_t lastMobileEnemy;
        std::time_t lastArmoredEnemy;
        std::time_t lastCombinedEnemy;
        std::time_t lastAmmoPack;
        std::time_t lastArmorPack;
        std::time_t lastHealthPack;
        std::time_t assasinTransition[2];
    public:
        int levelRender(sf::Event& event, sf::RenderWindow& window);
        void bulletPoll(sf::RenderWindow& window);
        void collision(sf::RenderWindow& window);
        void setEasyDifficulty();
        void setMediumDifficulty();
        void setHardDifficulty();
        void setCampaign();
        void spawnEntities(sf::RenderWindow& window);
        /**/void collisionAssasin(sf::RenderWindow& window);
        /**/void collisionBullet(auto props, int increaseScore);
        /**/void collides(auto it, sf::RenderWindow& window);
        void enemyFiresABullet(auto it, sf::RenderWindow& window);
        void clearVectors();
        void enemyBulletPoll(sf::RenderWindow& window);
        mainLevel();
        ~mainLevel();
};

#endif