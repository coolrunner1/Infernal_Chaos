#include "bullet.hpp"

bullet::bullet() : aliveEntity(){
    setSprite("Sprites/bullet.png");
    //entitySprite.setScale(3, 3);
    speed=4.4f;
    //bulletReachedEnd=false;
}

void bullet::bulletSet(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2i cursorPos){
    //bulletStart=playerPos;
    playerPos.x+=50;
    playerPos.y+=70;
    //cursorPos*=10;
    bulletEnd.x=cursorPos.x;
    bulletEnd.y=cursorPos.y;
    entitySprite.setPosition(playerPos);
    angle = atan2(bulletEnd.y-playerPos.y, bulletEnd.x-playerPos.x);
    //std::cout<<angle;
    bulletAngle=angle*180/3.14159;
    entitySprite.rotate(bulletAngle);
    //entitySprite.setRotation(angle);
    
    //float radians = angle * 3.14159 / 180.0;
    // Calculate the x and y components of the velocity vector
    //bulletEnd *= speed;
    // Apply the velocity to the sprite's position
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
    std::cout << "Bullet Position: (" << bulletPos.x << ", " << bulletPos.y << ")" << std::endl;
    return bulletPos;
}

bool bullet::bulletLifeCycle(){
    std::time(&current);
    return std::difftime(current, start)>5?true:false;
    /*if (bulletReachedEnd){
        std::cout<<"bullet destroyed";
    }*/
}
