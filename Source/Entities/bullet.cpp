#include "bullet.hpp"

bullet::bullet() : aliveEntity(){
    path="Sprites/bullet.png";
    setSprite(path);
    //entitySprite.setScale(3, 3);
    speed=4.4f;
    //bulletReachedEnd=false;
}

void bullet::bulletSet(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2i cursorPos){
    bulletEnd.x=cursorPos.x;
    bulletEnd.y=cursorPos.y;
    setupBullet(window, playerPos);
}

void bullet::bulletSetFloat(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2f endPos){
    bulletEnd=endPos;
    setupBullet(window, playerPos);
}

void bullet::setupBullet(sf::RenderWindow& window, sf::Vector2f playerPos){
    playerPos.x+=50;
    playerPos.y+=70;
    entitySprite.setPosition(playerPos);
    angle = atan2(bulletEnd.y-playerPos.y, bulletEnd.x-playerPos.x);
    bulletAngle=angle*180/3.14159;
    entitySprite.rotate(bulletAngle);
}

sf::Vector2f bullet::bulletMove(){
    //entitySprite.move(bulletEnd);
    entitySprite.move(speed*cos(angle),speed*sin(angle));
    bulletPos=entitySprite.getPosition();
    /*if (bulletPos.x<bulletEnd.x){
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
    }*/
    //std::cout << "Bullet Position: (" << bulletPos.x << ", " << bulletPos.y << ")" << std::endl;
    return bulletPos;
}

bool bullet::bulletLifeCycle(){
    std::time(&current);
    return std::difftime(current, start)>5?true:false;
    /*if (bulletReachedEnd){
        std::cout<<"bullet destroyed";
    }*/
}
