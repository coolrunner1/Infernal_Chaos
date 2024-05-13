#ifndef BULLET
#define BULLET
#include "aliveEntity.hpp"
#include <iostream>

class bullet : public aliveEntity{
    private:
        sf::Vector2f targetPos;
        //sf::Vector2f bulletStart;
        sf::Vector2f bulletEnd;
        sf::Vector2f bulletPos;
    public:
        void bulletSet(sf::RenderWindow& window, sf::Vector2f playerPos, sf::Vector2f cursorPos);
        sf::Vector2f bulletMove(bool& reachedEnd);
        bullet();
}
/*class aliveEntity : public entity{
    protected:
        int health;
        int armor;
        float speed;
    public:
        void healthDamage(int damage);
        aliveEntity();
        aliveEntity(int health, int armor);
};*/

#endif