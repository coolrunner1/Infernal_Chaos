#include "enemy.hpp"

enemy::enemy() : aliveEntity(){
    damage=0;
    speed=0;
    std::time(&damageTime);
    entitySprite.setScale(3, 3);
}


void enemy::enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos){
    entityPosition=entitySprite.getPosition();
    if (entityPosition.x<playerPos.x){
        setSprite(enemyPath[0]);
        entitySprite.move(speed, 0.0f);
    }
    if (entityPosition.x>playerPos.x){
        setSprite(enemyPath[1]);
        entitySprite.move(-speed, 0.0f);
    }
    if (entityPosition.y<playerPos.y){
        entitySprite.move(0.0f, speed);
    }
    if (entityPosition.y>playerPos.y){
        entitySprite.move(0.0f, -speed);
    }
    //std::cout << "Enemy Position: (" << entityPosition.x << ", " << entityPosition.y << ")" << std::endl;
}

int enemy::getDamage(){
    return damage;
}

void enemy::setDamageTime(std::time_t damageTime){
    this->damageTime=damageTime;
}

std::time_t enemy::getDamageTime(){
    return damageTime;
}