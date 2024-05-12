#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "aliveEntity.hpp"

class player : public aliveEntity{
    private:
        sf::Vector2f playerPosition;
        sf::Vector2i cursorPosition;
        sf::Texture cursorTexture;
        sf::Sprite cursor;
        sf::Font font;
        sf::Text healthText;
        sf::Text armorText;
        sf::Text ammoText;
        std::string currentHealth;
        std::string currentArmor;
        std::string currentAmmo;
    public:
        void playerMove(sf::Event& event, sf::RenderWindow& window);
        void playerRender(sf::RenderWindow& window);
        sf::Vector2f getPlayerPosition();
        player();
};
#endif
