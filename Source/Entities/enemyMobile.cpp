#include "enemyMobile.hpp"

enemyMobile::enemyMobile() : enemy(){
    setSprite("Sprites/rascal_right.png");
    speed=0.4f;
    damage=2;
    health=75;
    armor=0;
    enemyPath[0]="Sprites/rascal_right.png";
    enemyPath[1]="Sprites/rascal.png";
    //spawnInterval=2;
}

/*
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

int enemyMobile::getDamage(){
    return damage;
}

void enemyMobile::setDamageTime(std::time_t damageTime){
    this->damageTime=damageTime;
}

std::time_t enemyMobile::getDamageTime(){
    return damageTime;
}*/