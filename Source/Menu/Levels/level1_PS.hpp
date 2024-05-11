#ifndef LEVEL1_PS
#define LEVEL1_PS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "levelPattern.hpp"
class level1_PS{
    protected:
        player* myPlayer;
        
    public:
        level1_PS();
        ~level1_PS();
};

#endif
