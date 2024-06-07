#ifndef LEVELPATTERN
#define LEVELPATTERN
#include "../Entities/player.hpp"
#include "../Entities/cursor.hpp"
#include "stillScreen.hpp"
#include "stats.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class levelPattern{
    protected:
        player* myPlayer;
        cursor* myCursor;
        stats* myStats;
        stillScreen* stillScreens;
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
        levelPattern();
        levelPattern(std::string path);
        ~levelPattern();
};

#endif