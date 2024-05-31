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
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class levelPattern{
    protected:
        //bullet* tempBul;
        std::vector<bullet> bullets;
        std::vector<bullet> enemyBullets;
        std::vector<enemyMobile> mobileEnemies;
        std::vector<armoredEnemy> armoredEnemies;
        std::vector<combinedEnemy> combinedEnemies;
        std::vector<ammoPack> ammoPacks;
        std::vector<armorPack> armorPacks;
        std::vector<healthPack> healthPacks;
        player* myPlayer;
        sf::Vector2i cursorPosition;
        sf::Vector2f playerPosition;
        sf::Vector2f propPosition;
        sf::Vector2f bulletPosition;
        sf::Texture cursorTexture;
        sf::Sprite cursor;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        //ammoPack temp;
        //int bulletNum;
        float mobileInterval;
        float armoredInterval;
        float enemyFireInterval;
        float assasinSpawnInterval;
        float assasinInterval[2];
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
        int maxMobileEnemies;
        int maxShootingEnemies;
        int maxAssasins;
        bool boss;
    public:
        void movePlayer(sf::Event& event, sf::RenderWindow& window);
        int levelRender(sf::Event& event, sf::RenderWindow& window);
        void setBackground(sf::RenderWindow& window);
        void bulletPoll(sf::RenderWindow& window);
        void enemyBulletPoll(sf::RenderWindow& window);
        //void enemyMobilePoll(sf::RenderWindow& window);
        void levelInit();
        void collision(sf::RenderWindow& window);
        levelPattern();
        levelPattern(std::string path);
        ~levelPattern();
};

#endif