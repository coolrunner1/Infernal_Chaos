#ifndef ENTITY
#define ENTITY
#include <iostream>
#include <SFML/Graphics.hpp>

class entity{
    protected:
        int xpos;
        int ypos;
        
    public:
        sf::Sprite entitySprite;
        sf::Texture entityTexture;
        void entityDraw(sf::RenderWindow& window);
        void entityInit();
        void entityMove(int xpos, int ypos);
        entity();
        entity(int xpos, int ypos);
};
#endif
