#include "pickup.hpp"

pickup::pickup():entity(){
    xpos=generateRandomFloat(COLLISION_LEFT, COLLISION_RIGHT);
    ypos=generateRandomFloat(COLLISION_TOP, COLLISION_BOTTOM);
}

pickup::pickup(float xpos, float ypos):entity(){
    this->xpos=xpos;
    this->ypos=ypos;
}