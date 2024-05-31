#include "enemyMobile.hpp"

enemyMobile::enemyMobile() : aliveEntity(){
    setSprite("Sprites/rascal_right.png");
    entitySprite.setScale(3, 3);
    speed=0.4f;
}


void enemyMobile::enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos){
    enemyPos=entitySprite.getPosition();
    if (enemyPos.x<playerPos.x){
        setSprite("Sprites/rascal_right.png");
        entitySprite.move(speed, 0.0f);
    }
    if (enemyPos.x>playerPos.x){
        setSprite("Sprites/rascal.png");
        entitySprite.move(-speed, 0.0f);
    }
    if (enemyPos.y<playerPos.y){
        entitySprite.move(0.0f, speed);
    }
    if (enemyPos.y>playerPos.y){
        entitySprite.move(0.0f, -speed);
    }
    std::cout << "Enemy Position: (" << enemyPos.x << ", " << enemyPos.y << ")" << std::endl;
}