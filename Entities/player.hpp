#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "aliveEntity.hpp"

class player : public aliveEntity{
    private:
        int health;
        int armor;
    public:
        player();
};
#endif
