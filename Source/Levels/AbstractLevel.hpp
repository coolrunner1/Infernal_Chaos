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
#define CONTINUE_LEVEL_EXECUTION 7

class AbstractLevel {
    private:
        void levelInit();
        virtual void bulletPoll(sf::RenderWindow& window) = 0;
        virtual void update(sf::RenderWindow& window) = 0;
        virtual void spawnEntities(sf::RenderWindow& window) = 0;
        virtual void clearEntities() = 0;
        virtual void enemyBulletPoll(sf::RenderWindow& window) = 0;
    protected:
        Player* player;
        Cursor* cursor;
        Stats* stats;
        StillScreen* stillScreens;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundShape;
        bool endGame;
        int nextLevelCode;
        void keysCheck(sf::RenderWindow& window);
        void refreshBackground(sf::RenderWindow& window);
    public:
        void setBackground(std::string background);
        virtual int render(sf::Event& event, sf::RenderWindow& window) = 0;
        AbstractLevel();
        AbstractLevel(std::string path);
        ~AbstractLevel();
};

#endif