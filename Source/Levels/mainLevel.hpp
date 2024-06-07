#ifndef MAINLEVEL
#define MAINLEVEL
#include "levelPattern.hpp"
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
        std::vector<bullet> bullets;
        std::vector<bullet> enemyBullets;
        std::vector<ammoPack> ammoPacks;
        std::vector<armorPack> armorPacks;
        std::vector<healthPack> healthPacks;
        std::string path;
        std::vector<enemyMobile> mobileEnemies;
        std::vector<armoredEnemy> armoredEnemies;
        std::vector<combinedEnemy> combinedEnemies;
        boss* bossFinal;
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
        void collisionAssasin(auto props, sf::RenderWindow& window);
        void collisionArmored(auto props, sf::RenderWindow& window);
        void collisionBoss(sf::RenderWindow& window);
        void collisionBulletBoss(int increaseScore);
        void collisionBullet(auto props, int increaseScore);
        void collisionMobile(auto props, sf::RenderWindow& window);
        void enemyFiresABullet(auto it, sf::RenderWindow& window);
        void collidesBoss(sf::RenderWindow& window);
        void bulletFire(sf::Event& event, sf::RenderWindow& window);
        void clearVectors();
        void enemyBulletPoll(sf::RenderWindow& window);
        void collisionHealth(sf::RenderWindow& window);
        void collisionArmor(sf::RenderWindow& window);
        void collisionAmmo(sf::RenderWindow& window);
        void collides(auto it, sf::RenderWindow& window);
        mainLevel();
        ~mainLevel();
};

#endif