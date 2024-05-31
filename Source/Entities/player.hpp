#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "aliveEntity.hpp"

class player : public aliveEntity{
    private:
        sf::Vector2f playerPosition;
        sf::Vector2i cursorPosition;
        sf::Font font;
        sf::Text healthText;
        sf::Text armorText;
        sf::Text ammoText;
        std::string currentHealth;
        std::string currentArmor;
        std::string currentAmmo;
        int ammo;
    public:
        void playerMove(sf::Event& event, sf::RenderWindow& window);
        void playerRender(sf::RenderWindow& window);
        void ammoDecrement();
        void ammoIncrease(int newAmmo);
        int getAmmo();
        sf::Vector2f getPlayerPosition();
        player();
};
#endif
