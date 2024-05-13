#include "player.hpp"

player::player():aliveEntity(){
    std::cout<<"Player created\n";
    path="Sprites/main_char_idle_0.png";
    entitySprite.setScale(4, 4);
    entitySprite.setPosition(590, 260);
    speed=2.5f;
    if (!font.loadFromFile("Fonts/ARCADECLASSIC.TTF")) {
        std::cerr << "Missing file: Fonts/ARCADECLASSIC.TTF"<<std::endl;
    }
    healthText.setFont(font);
    armorText.setFont(font);
    ammoText.setFont(font);
    healthText.setFillColor(sf::Color::White);
    armorText.setFillColor(sf::Color::White);
    ammoText.setFillColor(sf::Color::White);
    healthText.setPosition(5, 0);
    armorText.setPosition(5, 30);
    ammoText.setPosition(5, 60);
}

void player::playerMove(sf::Event& event, sf::RenderWindow& window){
            cursorPosition=sf::Mouse::getPosition(window);
            playerPosition = entitySprite.getPosition();
            std::cout << "Player Position: (" << playerPosition.x << ", " << playerPosition.y << ")" << std::endl;
            std::cout << "Cursor Position: (" << cursorPosition.x << ", " << cursorPosition.y << ")" << std::endl;
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && playerPosition.x>-2.5) {
                entitySprite.move(-speed, 0.0f);
                setSprite("Sprites/main_char_left.png");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerPosition.x<1207.5) {
                entitySprite.move(speed, 0.0f);
                setSprite("Sprites/main_char_idle_0.png");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) && playerPosition.y>-2.5) {
                entitySprite.move(0.0f, -speed);
                setSprite("Sprites/main_char_back.png");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) && playerPosition.y<615) {
                entitySprite.move(0.0f, speed);
                setSprite("Sprites/main_char_front.png");
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (playerPosition.x>cursorPosition.x){
                    setSprite("Sprites/main_char_left.png");
                }
                else if (playerPosition.x<cursorPosition.x){
                    setSprite("Sprites/main_char_idle_0.png");
                }
            }
}

sf::Vector2f player::getPlayerPosition(){
    return entitySprite.getPosition();
}

void player::playerRender(sf::RenderWindow& window){
    entityDraw(window);
    currentHealth="Health "+std::to_string(health);
    healthText.setString(currentHealth);
    window.draw(healthText);
    currentArmor="Armor "+std::to_string(armor);
    armorText.setString(currentArmor);
    window.draw(armorText);
    currentAmmo="Ammo placeholder"/*+std::to_string(ammo)*/;
    ammoText.setString(currentAmmo);
    window.draw(ammoText);
}