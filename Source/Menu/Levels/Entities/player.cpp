#include "player.hpp"

player::player():aliveEntity(){
    std::cout<<"Player created\n";
    path="Sprites/main_char_idle_0.png";
    entitySprite.setScale(4, 4);
    entitySprite.setPosition(590, 260);
    if (!cursorTexture.loadFromFile("Sprites/Cursor.png")) {
                std::cerr << "Missing file: Sprites/Cursor.png"<<std::endl;
        }
    cursor.setTexture(cursorTexture);
    cursor.setScale(3, 3);
    speed=2.5f;
}

void player::playerMove(sf::Event& event, sf::RenderWindow& window){
            cursorPosition=sf::Mouse::getPosition(window);
            cursor.setPosition(cursorPosition.x-25, cursorPosition.y-25);
            window.draw(cursor);
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
