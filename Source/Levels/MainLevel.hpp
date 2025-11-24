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
#define ETERNAL 1
#define BOSS_BONUS 1000

class MainLevel : public AbstractLevel{
    protected:
        std::vector<Bullet> bullets;
        std::vector<Bullet> enemyBullets;
        AbstractEntityContainer* entitySlot1;
        AbstractEntityContainer* entitySlot2; 
        AbstractEntityContainer* entitySlot3; 
        AbstractEntityContainer* entitySlot4; 
        AbstractEntityContainer* entitySlot5; 
        AbstractEntityContainer* entitySlot6;  
        AbstractEnemyContainer* enemySlot1; 
        AbstractEnemyContainer* enemySlot2; 
        AbstractEnemyContainer* enemySlot3; 
        AbstractEnemyContainer* enemySlot4; 
        AbstractEnemyContainer* enemySlot5; 
        AbstractEnemyContainer* enemySlot6; 
        AbstractEnemyContainer* boss;
        std::string path;
        int mode;
        bool bossSpawned;
        int bossReachScore;
        std::string bossBackground;
    public:
        int levelRender(sf::Event& event, sf::RenderWindow& window);
        void bulletPoll(sf::RenderWindow& window);
        void update(sf::RenderWindow& window);
        void spawnEntities(sf::RenderWindow& window);
        void clearVectors();
        void enemyBulletPoll(sf::RenderWindow& window);
        MainLevel(
            std::string background,
            int bossReachScore,
            std::string bossBackground,
            int nextLevelCode,
            AbstractEntityContainer* entitySlot1, 
            AbstractEntityContainer* entitySlot2, 
            AbstractEntityContainer* entitySlot3, 
            AbstractEntityContainer* entitySlot4, 
            AbstractEntityContainer* entitySlot5, 
            AbstractEntityContainer* entitySlot6,  
            AbstractEnemyContainer* enemySlot1, 
            AbstractEnemyContainer* enemySlot2, 
            AbstractEnemyContainer* enemySlot3, 
            AbstractEnemyContainer* enemySlot4, 
            AbstractEnemyContainer* enemySlot5, 
            AbstractEnemyContainer* enemySlot6,
            AbstractEnemyContainer* boss
        );
        MainLevel(
            std::string background,
            AbstractEntityContainer* entitySlot1, 
            AbstractEntityContainer* entitySlot2, 
            AbstractEntityContainer* entitySlot3, 
            AbstractEntityContainer* entitySlot4, 
            AbstractEntityContainer* entitySlot5, 
            AbstractEntityContainer* entitySlot6,  
            AbstractEnemyContainer* enemySlot1, 
            AbstractEnemyContainer* enemySlot2, 
            AbstractEnemyContainer* enemySlot3, 
            AbstractEnemyContainer* enemySlot4, 
            AbstractEnemyContainer* enemySlot5, 
            AbstractEnemyContainer* enemySlot6
        );
        ~MainLevel();
};

#endif