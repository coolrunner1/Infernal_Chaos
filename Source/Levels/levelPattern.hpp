#ifndef LEVELPATTERN
#define LEVELPATTERN
#include "../Entities/player.hpp"
#include "../Entities/enemyMobile.hpp"
#include "../Entities/bullet.hpp"
#include "../Entities/ammoPack.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

class levelPattern{
    protected:
        //bullet* tempBul;
        std::vector<bullet> bullets;
        player* myPlayer;
        sf::Vector2i cursorPosition;
        sf::Vector2f playerPosition;
        sf::Vector2f enemyPosition;
        sf::Texture cursorTexture;
        sf::Sprite cursor;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        std::vector<enemyMobile> mobileEnemies;
        std::vector<ammoPack> ammoPacks;
        int bulletNum;
        float mobileInterval;
        std::time_t start;
        std::time_t current;
        std::time_t prevDamage;
        int pickupSpawnInterval;
        int maxMobileEnemies;
        int maxShootingEnemies;
        int maxAssasins;
        bool boss;
    public:
        void movePlayer(sf::Event& event, sf::RenderWindow& window);
        void levelRender(sf::Event& event, sf::RenderWindow& window);
        void setBackground(sf::RenderWindow& window);
        void bulletPoll(sf::RenderWindow& window);
        void enemyMobilePoll(sf::RenderWindow& window);
        void levelInit();
        void collision(sf::RenderWindow& window);
        levelPattern();
        levelPattern(std::string path);
        ~levelPattern();
};

#endif