#ifndef MAINLEVEL
#define MAINLEVEL
#include "AbstractLevel.hpp"
#include "../Entities/EnemyMobile.hpp"
#include "../Entities/Bullet.hpp"
#include "../Entities/AmmoPack.hpp"
#include "../Entities/ArmorPack.hpp"
#include "../Entities/HealthPack.hpp"
#include "../Entities/ArmoredEnemy.hpp"
#include "../Entities/CombinedEnemy.hpp"
#include "../Entities/Boss.hpp"
#include "../EntityContainers/MobileEnemiesContainer.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#define CAMPAIGN 0
#define SUFFERING_EASY 1
#define SUFFERING_MEDIUM 2
#define SUFFERING_HARD 3

class MainLevel : public AbstractLevel{
    protected:
        std::vector<Bullet> bullets;
        std::vector<Bullet> enemyBullets;
        std::vector<AmmoPack> ammoPacks;
        std::vector<ArmorPack> armorPacks;
        std::vector<HealthPack> healthPacks;
        std::string path;
        MobileEnemiesContainer* mobileEnemies;
        std::vector<ArmoredEnemy> armoredEnemies;
        std::vector<CombinedEnemy> combinedEnemies;
        Boss* boss;
        float assasinSpawnInterval;
        float assasinInterval[2];
        float armoredInterval;
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
        void collisionAssasin(sf::RenderWindow& window);
        void collisionArmored(sf::RenderWindow& window);
        void collisionBoss(sf::RenderWindow& window);
        void collisionBulletBoss(int increaseScore);
        template <typename T>
        void collisionBullet(T props, int increaseScore);
        template <typename T>
        void enemyFiresABullet(T it, sf::RenderWindow& window);
        void collidesBoss(sf::RenderWindow& window);
        void bulletFire(sf::Event& event, sf::RenderWindow& window);
        void clearVectors();
        void enemyBulletPoll(sf::RenderWindow& window);
        void collisionHealth(sf::RenderWindow& window);
        void collisionArmor(sf::RenderWindow& window);
        void collisionAmmo(sf::RenderWindow& window);
        template <typename T>
        void collides(T it, sf::RenderWindow& window);
        MainLevel();
        ~MainLevel();
};

#endif