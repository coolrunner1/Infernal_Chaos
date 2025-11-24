#ifndef ARMOREDENEMY
#define ARMOREDENEMY
#include "Enemy.hpp"
#include "Bullet.hpp"

class ArmoredEnemy: public Enemy {
    private:
        void armoredInit(int fireInterval = 5);
        int fireInterval;
    protected:
        std::time_t lastFired;
        float bulletDamage;
    public:
        void setFired(std::time_t fired);
        std::time_t getLastFired();
        void fireABullet(std::vector<Bullet>& bullets, sf::RenderWindow& window, sf::Vector2f playerPosition);
        int getFireInterval();
        void setFireInterval(int fireInterval);
        ArmoredEnemy();
        ArmoredEnemy(int fireInterval);
        ArmoredEnemy(bool robot);
};
#endif
