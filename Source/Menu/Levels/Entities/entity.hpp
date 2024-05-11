#ifndef ENTITY
#define ENTITY
#include <iostream>
#include <SFML/Graphics.hpp>

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
