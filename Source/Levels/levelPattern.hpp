#ifndef LEVELPATTERN
#define LEVELPATTERN
#include "../Entities/player.hpp"
#include "../Entities/enemyMobile.hpp"
#include "../Entities/bullet.hpp"
#include "../Entities/ammoPack.hpp"
#include "../Entities/armorPack.hpp"
#include "../Entities/healthPack.hpp"
#include "../Entities/armoredEnemy.hpp"
#include "../Entities/combinedEnemy.hpp"
#include "../Entities/boss.hpp"
#include "../Entities/cursor.hpp"
#include "stillScreen.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class levelPattern{
    protected:
        std::vector<bullet> bullets;
        std::vector<bullet> enemyBullets;
        std::vector<enemyMobile> mobileEnemies;
        std::vector<armoredEnemy> armoredEnemies;
        std::vector<combinedEnemy> combinedEnemies;
        std::vector<ammoPack> ammoPacks;
        std::vector<armorPack> armorPacks;
        std::vector<healthPack> healthPacks;
        boss* bossFinal;
        player* myPlayer;
        cursor* myCursor;
        sf::Vector2f playerPosition;
        sf::Vector2f bulletPosition;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        float mobileInterval;
        float armoredInterval;
        float enemyFireInterval;
        float assasinSpawnInterval;
        float assasinInterval[2];
        float enemyBulletDamage;
        std::time_t start;
        std::time_t current;
        std::time_t prevDamage;
        std::time_t lastMobileEnemy;
        std::time_t lastArmoredEnemy;
        std::time_t lastCombinedEnemy;
        std::time_t lastAmmoPack;
        std::time_t lastArmorPack;
        std::time_t lastHealthPack;
        std::time_t assasinTransition[2];
        int shootingDamage;
        int pickupSpawnInterval;
        int mode;
        bool bossSpawned;
        bool bossDefeated;
        stillScreen* stillScreens;
    public:
        void keysCheck(sf::RenderWindow& window);
        int levelRender(sf::Event& event, sf::RenderWindow& window);
        void setBackground(sf::RenderWindow& window);
        void bulletPoll(sf::RenderWindow& window);
        void enemyBulletPoll(sf::RenderWindow& window);
        void clearVectors();
        void levelInit();
        void collision(sf::RenderWindow& window);
        void setEasyDifficulty();
        void setMediumDifficulty();
        void setHardDifficulty();
        void setCampaign();
        void spawnEntities(sf::RenderWindow& window);
        levelPattern();
        levelPattern(std::string path);
        ~levelPattern();
};

#endif