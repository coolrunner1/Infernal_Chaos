#ifndef ENTITY
#define ENTITY
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Functions/randomFloat.hpp"
#include "../Functions/randomInt.hpp"
#include <chrono>
#include <ctime>
#define COLLISION_TOP -2.5
#define COLLISION_LEFT -2.5
#define COLLISION_RIGHT 1207.5
#define COLLISION_BOTTOM 615 

class entity{
    protected:
        int xpos;
        int ypos;
        int spawnInterval;
        std::string path;
        sf::Vector2f entityPosition;
        std::time_t start;
        sf::Sprite entitySprite;
        sf::Texture entityTexture;
    public:
        void entityDraw(sf::RenderWindow& window);
        void entityInit();
        void entityMove(int xpos, int ypos);
        void refresh();
        void setSprite(std::string path);
        int getSpawnInterval();
        void setSpawnInterval(int interval);
        bool collidesWithPlayer(sf::Vector2f playerPosition);
        sf::Vector2f getPosition();
        std::time_t getTime();
        entity();
        entity(int xpos, int ypos, std::string path);
};
#endif
