#ifndef COMBINEDENEMY
#define COMBINEDENEMY
#include "ArmoredEnemy.hpp"
#include <iostream>

class CombinedEnemy : public ArmoredEnemy {
    private:
        void combinedEnemyInit();
    protected:
        std::time_t transitionToSlowTimestamp;
        std::time_t transitionToFastTimestamp;
        float transitionToSlowInterval;
        float transitionToFastInterval;
    public:
        std::time_t getTransitionToSlowTimestamp();
        std::time_t getTransitionToFastTimestamp();
        void updateTransitionToSlowTimestamp();
        void updateTransitionToFastTimestamp();
        void enemyMove(sf::RenderWindow& window, sf::Vector2f playerPos);
        void setHighSpeed();
        void setLowSpeed();
        CombinedEnemy(float transitionToSlowInterval, float transitionToFastInterval);
        CombinedEnemy(float transitionToSlowInterval, float transitionToFastInterval, bool assasin);
};
#endif
