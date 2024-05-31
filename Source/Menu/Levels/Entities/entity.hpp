#ifndef ENTITY
#define ENTITY
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../../Functions/randomFloat.hpp"
#include "../../../Functions/randomInt.hpp"
#define COLLISION_TOP -2.5
#define COLLISION_LEFT -2.5
#define COLLISION_RIGHT 1207.5
#define COLLISION_BOTTOM 615 

class entity{
    protected:
        int xpos;
        int ypos;
        std::string path;
        sf::Vector2f enemyPos;
    public:
        sf::Sprite entitySprite;
        sf::Texture entityTexture;
        void entityDraw(sf::RenderWindow& window);
        void entityInit();
        void entityMove(int xpos, int ypos);
        void setSprite(std::string path);
        entity();
        entity(int xpos, int ypos, std::string path);
};
#endif
