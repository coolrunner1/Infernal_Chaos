#include "stats.hpp"

stats::stats(){
    if (!font.loadFromFile("Fonts/ARCADECLASSIC.TTF")) {
        std::cerr << "Missing file: Fonts/ARCADECLASSIC.TTF"<<std::endl;
    }
    healthText.setFont(font);
    armorText.setFont(font);
    ammoText.setFont(font);
    scoreText.setFont(font);
    healthText.setFillColor(sf::Color::White);
    armorText.setFillColor(sf::Color::White);
    ammoText.setFillColor(sf::Color::White);
    scoreText.setFillColor(sf::Color::White);
    healthText.setPosition(5, 0);
    armorText.setPosition(5, 30);
    ammoText.setPosition(5, 60);
    scoreText.setPosition(1050, 0);
}

void stats::statsRender(sf::RenderWindow& window, int health, int armor, int ammo, int score){
    currentHealth="Health "+std::to_string(health);
    healthText.setString(currentHealth);
    window.draw(healthText);
    currentArmor="Armor "+std::to_string(armor);
    armorText.setString(currentArmor);
    window.draw(armorText);
    currentAmmo="Ammo "+std::to_string(ammo);
    ammoText.setString(currentAmmo);
    window.draw(ammoText);
    currentScore="Score "+std::to_string(score);
    scoreText.setString(currentScore);
    window.draw(scoreText);
}