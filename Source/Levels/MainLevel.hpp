#ifndef MAINLEVEL
#define MAINLEVEL
#include "AbstractLevel.hpp"
#include "../Entities/Bullet.hpp"
#include "../Entities/AmmoPack.hpp"
#include "../Entities/ArmoredEnemy.hpp"
#include "../Entities/CombinedEnemy.hpp"
#include "../EntityContainers/CombinedEnemiesContainer.hpp"
#include <memory>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#define CAMPAIGN 0
#define ETERNAL 1

class MainLevel : public AbstractLevel{
    protected:
        std::vector<Bullet> bullets;
        std::vector<Bullet> enemyBullets;
        std::vector<AbstractEntityContainer*> entityContainers;
        std::vector<AbstractEnemyContainer*> enemyContainers;
        AbstractEnemyContainer* boss;
        std::string path;
        int mode;
        bool bossSpawned;
        int bossReachScore;
        std::string bossBackground;
    public:
        /*
        * Calls methods necessary for level rendering and returns a value that signals to either create the next level or to continue running the current level
        */
        int levelRender(sf::Event& event, sf::RenderWindow& window);
        /*
        * Calls methods of containers to check if bullets fired by the player collide with enemies
        */
        void bulletPoll(sf::RenderWindow& window);
        /*
        * Calls methods of containers that are responsible for updating entity states
        */
        void update(sf::RenderWindow& window);
        /*
        * Calls methods of containers that are responsible for entity spawning
        */
        void spawnEntities(sf::RenderWindow& window);
        /*
        * Deletes all entities
        */
        void clearEntities();
        /*
        * Checks if bullets fired by enemies collide with the player
        */
        void enemyBulletPoll(sf::RenderWindow& window);
        /*
        * This constructor initializes level with the "campaign" mode
        */
        MainLevel(
            std::string background,
            std::vector<AbstractEntityContainer*>& entitiesContainers,
            std::vector<AbstractEnemyContainer*>& enemyContainers,
            int bossReachScore,
            std::string bossBackground,
            int nextLevelCode,
            AbstractEnemyContainer* boss
        );
        /*
        * This constructor initializes level with the "perpetual" mode
        */
        MainLevel(
            std::string background,
            std::vector<AbstractEntityContainer*>& entitiesContainers,
            std::vector<AbstractEnemyContainer*>& enemyContainers
        );
        ~MainLevel();
};

#endif