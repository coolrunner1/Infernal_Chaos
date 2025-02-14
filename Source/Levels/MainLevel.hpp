#ifndef MAINLEVEL
#define MAINLEVEL
#include "LevelPattern.hpp"
#include "../Entities/EnemyMobile.hpp"
#include "../Entities/Bullet.hpp"
#include "../Entities/AmmoPack.hpp"
#include "../Entities/ArmorPack.hpp"
#include "../Entities/HealthPack.hpp"
#include "../Entities/ArmoredEnemy.hpp"
#include "../Entities/CombinedEnemy.hpp"
#include "../Entities/Boss.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class MainLevel : public LevelPattern{
    protected:
        std::vector<Bullet> bullets;
        std::vector<Bullet> enemyBullets;
        std::vector<AmmoPack> ammoPacks;
        std::vector<ArmorPack> armorPacks;
        std::vector<HealthPack> healthPacks;
        std::string path;
        std::vector<EnemyMobile> mobileEnemies;
        std::vector<ArmoredEnemy> armoredEnemies;
        std::vector<CombinedEnemy> combinedEnemies;
        Boss* bossFinal;
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
        void collisionAssasin(sf::RenderWindow& window);
        void collisionArmored(sf::RenderWindow& window);
        void collisionBoss(sf::RenderWindow& window);
        void collisionBulletBoss(int increaseScore);
        template <typename T>
        void collisionBullet(T props, int increaseScore);
        void collisionMobile(sf::RenderWindow& window);
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