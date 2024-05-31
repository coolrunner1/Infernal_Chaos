#ifndef PICKUP
#define PICKUP
#include "entity.hpp"
#include <iostream>

class pickup : public entity{
    protected:
        float xpos;
        float ypos;
    public:
        pickup();
};
#endif
