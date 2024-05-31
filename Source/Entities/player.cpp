#include "player.hpp"

player::player():aliveEntity(){
    std::cout<<"Player created\n";
    //path="Sprites/main_char_idle_0.png";
    entitySprite.setScale(4, 4);
    entitySprite.setPosition(590, 260);
    speed=2.5f;
    if (!font.loadFromFile("Fonts/ARCADECLASSIC.TTF")) {
        std::cerr << "Missing file: Fonts/ARCADECLASSIC.TTF"<<std::endl;
    }
    ammo=50;
    score=0;
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
    setSprite("Sprites/main_char_idle_0.png");
}

void player::playerMove(sf::Event& event, sf::RenderWindow& window){
            cursorPosition=sf::Mouse::getPosition(window);
            playerPosition = entitySprite.getPosition();
            //std::cout << "Player Position: (" << playerPosition.x << ", " << playerPosition.y << ")" << std::endl;
            //std::cout << "Cursor Position: (" << cursorPosition.x << ", " << cursorPosition.y << ")" << std::endl;
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && playerPosition.x>COLLISION_LEFT) {
                entitySprite.move(-speed, 0.0f);
                setSprite("Sprites/main_char_left.png");
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && playerPosition.x<COLLISION_RIGHT) {
                entitySprite.move(speed, 0.0f);
                setSprite("Sprites/main_char_idle_0.png");
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && playerPosition.y>COLLISION_TOP) {
                entitySprite.move(0.0f, -speed);
                setSprite("Sprites/main_char_back.png");
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && playerPosition.y<COLLISION_BOTTOM) {
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

void player::playerRender(sf::RenderWindow& window){
    entityDraw(window);
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

void player::ammoDecrement(){
    --ammo;
}

int player::getAmmo(){
    return ammo;
}

void player::ammoIncrease(int newAmmo){
    ammo+=newAmmo;
}

void player::healthIncrease(int newHealth){
    if (health+newHealth>100){
        health=100;
        return;
    }
    health+=newHealth;
}

void player::armorIncrease(int newArmor){
    if (armor+newArmor>100){
        armor=100;
        return;
    }
    armor+=newArmor;
}

void player::scoreIncrease(int newScore){
    score+=newScore;
}

int player::getScore(){
    return score;
}