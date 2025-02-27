#ifndef ABSTRACT_LEVEL
#define ABSTRACT_LEVEL
#include "../Entities/Player.hpp"
#include "../Entities/Cursor.hpp"
#include "StillScreen.hpp"
#include "Stats.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class AbstractLevel {
    protected:
        Player* player;
        Cursor* cursor;
        Stats* stats;
        StillScreen* stillScreens;
        sf::Vector2f playerPosition;
        sf::Vector2f bulletPosition;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        /**/
        float enemyBulletDamage;
        /**/
        float enemyFireInterval;
        std::time_t start;
        std::time_t current;
        /**/
        std::time_t prevDamage;
        /**/
        int shootingDamage;
        int mode;
        bool bossSpawned;
        bool bossDefeated;
    public:
        void keysCheck(sf::RenderWindow& window);
        void setBackground(sf::RenderWindow& window);
        void levelInit();
        AbstractLevel();
        AbstractLevel(std::string path);
        ~AbstractLevel();
};

#endif