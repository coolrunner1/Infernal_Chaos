#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "aliveEntity.hpp"

class player : public aliveEntity{
    private:
        sf::Vector2f playerPosition;
        sf::Vector2i cursorPosition;
        int ammo;
        int score;
    public:
        void playerMove(sf::Event& event, sf::RenderWindow& window);
        void playerRender(sf::RenderWindow& window);
        void ammoDecrement();
        void ammoIncrease(int newAmmo);
        void healthIncrease(int newHealth);
        void armorIncrease(int newArmor);
        void scoreIncrease(int newScore);
        int getScore();
        int getAmmo();
        player();
};
#endif
