#include "player.hpp"

player::player():aliveEntity(){
    std::cout<<"Player created\n";
    path="Sprites/main_char_idle_0.png";
    entitySprite.setScale(4, 4);
}

void player::playerMove(sf::Event& event, sf::RenderWindow& window){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                entitySprite.move(-2.5f, 0.0f);
                setSprite("Sprites/main_char_left.png");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                std::cout<<"r\n";
                entitySprite.move(2.5f, 0.0f);
                setSprite("Sprites/main_char_idle_0.png");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                entitySprite.move(0.0f, -2.5f);
                setSprite("Sprites/main_char_back.png");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                entitySprite.move(0.0f, 2.5f);
                setSprite("Sprites/main_char_front.png");
            }
}