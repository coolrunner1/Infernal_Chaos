#include "AliveEntity.hpp"

AliveEntity::AliveEntity() : Entity() {
    health = 100;
    armor = 100;
    speed = 0.5f;
}


AliveEntity::AliveEntity(int health, int armor) : Entity(xpos, ypos, path) {
    this->health = health;
    this->armor = armor;
    this->speed = speed;
}

void AliveEntity::healthDamage(int damage) {
    if (armor >= damage) {
        armor -= damage;
    } else {
        armor -= damage;
        health += armor;
        armor = 0;
    }
}

int AliveEntity::getHealth() {
    return health;
}

int AliveEntity::getArmor() {
    return armor;
}