#ifndef LEVELPATTERN
#define LEVELPATTERN
#include "../Entities/Player.hpp"
#include "../Entities/Cursor.hpp"
#include "StillScreen.hpp"
#include "Stats.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class LevelPattern{
    protected:
        Player* myPlayer;
        Cursor* myCursor;
        Stats* myStats;
        StillScreen* stillScreens;
        sf::Vector2f playerPosition;
        sf::Vector2f bulletPosition;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        float enemyBulletDamage;
        float enemyFireInterval;
        std::time_t start;
        std::time_t current;
        std::time_t prevDamage;
        int shootingDamage;
        int pickupSpawnInterval;
        int mode;
        bool bossSpawned;
        bool bossDefeated;
    public:
        void keysCheck(sf::RenderWindow& window);
        void setBackground(sf::RenderWindow& window);
        void levelInit();
        LevelPattern();
        LevelPattern(std::string path);
        ~LevelPattern();
};

#endif