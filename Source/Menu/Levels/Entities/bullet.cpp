#include "bullet.hpp"

bullet::bullet() : aliveEntity(){
    setSprite("Sprites/bullet.png");
    //entitySprite.setScale(3, 3);
    speed=3.4f;
}

void bullet::bulletSet(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2f cursorPos){
    //bulletStart=playerPos;
    bulletEnd=cursorPos;
    entitySprite.setPosition(playerPos);
}

sf::Vector2f bullet::bulletMove(bool& reachedEnd){
    bulletPos=entitySprite.getPosition();
    if (bulletPos.x<bulletEnd.x){
        entitySprite.move(speed, 0.0f);
    }
    if (bulletPos.x>bulletEnd.x){
        entitySprite.move(-speed, 0.0f);
    }
    if (bulletPos.y<bulletEnd.y){
        entitySprite.move(0.0f, speed);
    }
    if (bulletPos.y>bulletEnd.y){
        entitySprite.move(0.0f, -speed);
    }
    if (bulletPos==bulletEnd){
        reachedEnd=true;
    }
    else{
        reachedEnd=false;
    }
    std::cout << "Bullet Position: (" << bulletPos.x << ", " << bulletPos.y << ")" << std::endl;
}