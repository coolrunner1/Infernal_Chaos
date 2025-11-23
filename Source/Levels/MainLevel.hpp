#ifndef MAINLEVEL
#define MAINLEVEL
#include "AbstractLevel.hpp"
#include "../Entities/Bullet.hpp"
#include "../Entities/AmmoPack.hpp"
#include "../Entities/ArmoredEnemy.hpp"
#include "../Entities/CombinedEnemy.hpp"
#include "../EntityContainers/CombinedEnemiesContainer.hpp"
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
        AbstractEntityContainer* ammoPacks;
        AbstractEntityContainer* armorPacks;
        AbstractEntityContainer* healthPacks;
        AbstractEnemyContainer* mobileEnemies;
        AbstractEnemyContainer* armoredEnemies;
        AbstractEnemyContainer* combinedEnemies;
        AbstractEnemyContainer* boss;
        std::string path;
    public:
        int levelRender(sf::Event& event, sf::RenderWindow& window);
        void bulletPoll(sf::RenderWindow& window);
        void collision(sf::RenderWindow& window);
        void setEasyDifficulty();
        void setMediumDifficulty();
        void setHardDifficulty();
        void setCampaign();
        void spawnEntities(sf::RenderWindow& window);
        void clearVectors();
        void enemyBulletPoll(sf::RenderWindow& window);
        MainLevel(
            AbstractEntityContainer* ammoPacks,
            AbstractEntityContainer* armorPacks, 
            AbstractEntityContainer* healthPacks, 
            AbstractEnemyContainer* mobileEnemies, 
            AbstractEnemyContainer* armoredEnemies,
            AbstractEnemyContainer* combinedEnemies,
            AbstractEnemyContainer* boss
        );
        ~MainLevel();
};

#endif