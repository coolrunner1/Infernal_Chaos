#include "levelPattern.hpp"

levelPattern::levelPattern(){
        myPlayer = new player;
}

levelPattern::~levelPattern(){
        delete myPlayer;
}

void levelPattern::movePlayer(sf::Event& event, sf::RenderWindow& window){
        
}



/*player* sprt = new player;
sprt->entityDraw(window);
        sprt->playerMove(event, window);*/