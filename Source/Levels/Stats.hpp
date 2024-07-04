#ifndef STATS
#define STATS
#include <iostream>
#include "../Entities/Player.hpp"

class Stats {
    private:
        sf::Font font;
        sf::Text healthText;
        sf::Text armorText;
        sf::Text ammoText;
        sf::Text scoreText;
        std::string currentHealth;
        std::string currentArmor;
        std::string currentAmmo;
        std::string currentScore;
    public:
        void statsRender(sf::RenderWindow& window, int health, int armor, int ammo, int score);
        Stats();
};
#endif
