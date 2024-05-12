#include "levelPattern.hpp"

levelPattern::levelPattern(){
        levelInit();
        if (!backgroundTexture.loadFromFile("Sprites/lvl1_bg.png")) {
                std::cerr << "Missing file: Sprites/lvl1_bg.png"<<std::endl;
        }
}

levelPattern::levelPattern(std::string path){
        levelInit();
        if (!backgroundTexture.loadFromFile(path)) {
                std::cerr << "Missing file: "<<path<<std::endl;
        }
}

void levelPattern::levelRender(sf::Event& event, sf::RenderWindow& window){
        setBackground(window);
        window.setMouseCursorVisible(false);
        test->entityDraw(window);
        test->enemyMove(window, myPlayer->getPlayerPosition());
        myPlayer->playerRender(window);
        myPlayer->playerMove(event, window);
}

void levelPattern::levelInit(){
        std::cout<<"Level created\n";
        myPlayer = new player;
        test=new enemyMobile;
}

levelPattern::~levelPattern(){
        delete myPlayer;
}

void levelPattern::setBackground(sf::RenderWindow& window){
        backgroundShape.setTexture(backgroundTexture);
        window.draw(backgroundShape);
}

void levelPattern::movePlayer(sf::Event& event, sf::RenderWindow& window){
        
}



/*player* sprt = new player;
sprt->entityDraw(window);
        sprt->playerMove(event, window);*/