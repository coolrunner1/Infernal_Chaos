#ifndef LEVELPATTERN
#define LEVELPATTERN
#include "Entities/player.hpp"
#include "Entities/enemyMobile.hpp"
#include "Entities/bullet.hpp"
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
        enemyMobile* test;
        sf::Vector2i cursorPosition;
        sf::Texture cursorTexture;
        sf::Sprite cursor;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        std::vector<enemyMobile*> mobileEnemies;
        int bulletNum;
        std::time_t current;
    public:
        void movePlayer(sf::Event& event, sf::RenderWindow& window);
        void levelRender(sf::Event& event, sf::RenderWindow& window);
        void setBackground(sf::RenderWindow& window);
        void bulletPoll(sf::RenderWindow& window);
        void levelInit();
        levelPattern();
        levelPattern(std::string path);
        ~levelPattern();
};

#endif