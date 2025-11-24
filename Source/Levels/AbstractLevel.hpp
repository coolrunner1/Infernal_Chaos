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
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        bool endGame;
    public:
        void keysCheck(sf::RenderWindow& window);
        void setBackground(std::string background);
        void refreshBackground(sf::RenderWindow& window);
        void levelInit();
        virtual int levelRender(sf::Event& event, sf::RenderWindow& window) = 0;
        virtual void bulletPoll(sf::RenderWindow& window) = 0;
        virtual void update(sf::RenderWindow& window) = 0;
        virtual void spawnEntities(sf::RenderWindow& window) = 0;
        virtual void clearVectors() = 0;
        virtual void enemyBulletPoll(sf::RenderWindow& window) = 0;
        AbstractLevel();
        AbstractLevel(std::string path);
        ~AbstractLevel();
};

#endif