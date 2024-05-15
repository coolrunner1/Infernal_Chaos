#include "bullet.hpp"

bullet::bullet() : aliveEntity(){
    setSprite("Sprites/bullet.png");
    //entitySprite.setScale(3, 3);
    speed=3.4f;
}

void bullet::bulletSet(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2i cursorPos){
    //bulletStart=playerPos;
    playerPos.x+=50;
    playerPos.y+=70;
    //cursorPos*=10;
    bulletEnd=cursorPos;
    entitySprite.setPosition(playerPos);
    entitySprite.rotate(atan2(bulletEnd.y-playerPos.y, bulletEnd.x-playerPos.x)*(-1));
    //angle = atan2(p1.y - p2.y, p1.x - p2.x)
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
    if (bulletPos.x==bulletEnd.x){
        reachedEnd=true;
    }
    else{
        reachedEnd=false;
    }
    std::cout << "Bullet Position: (" << bulletPos.x << ", " << bulletPos.y << ")" << std::endl;
    return bulletPos;
}