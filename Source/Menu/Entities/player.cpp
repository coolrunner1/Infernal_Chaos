#include "player.hpp"

player::player():aliveEntity(){
    
}

void player::playerMove(sf::Event& event, sf::RenderWindow& window){

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    entitySprite.move(-0.1f, 0.0f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    entitySprite.move(0.1f, 0.0f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    entitySprite.move(0.0f, -0.1f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    entitySprite.move(0.0f, 0.1f);
                }
            }
}