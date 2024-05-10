#include "levelPattern.hpp"

levelPattern::levelPattern(){
        std::cout<<"Level created\n";
        myPlayer = new player;
}

void levelPattern::levelRender(sf::Event& event, sf::RenderWindow& window){
        myPlayer->entityDraw(window);
        myPlayer->playerMove(event, window);
}

levelPattern::~levelPattern(){
        delete myPlayer;
}

void levelPattern::movePlayer(sf::Event& event, sf::RenderWindow& window){
        
}



/*player* sprt = new player;
sprt->entityDraw(window);
        sprt->playerMove(event, window);*/