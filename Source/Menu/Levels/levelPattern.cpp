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
        myPlayer->entityDraw(window);
        myPlayer->playerMove(event, window);
        window.draw(cursor);
        cursor.setScale(4, 4);
        cursor.setPosition(200, 200/*sf::Mouse::getPosition(window)*/);/*move*/
}

void levelPattern::levelInit(){
        std::cout<<"Level created\n";
        myPlayer = new player;
        if (!backgroundTexture.loadFromFile("Sprites/Cursor.png")) {
                std::cerr << "Missing file: Sprites/Cursor.png"<<std::endl;
        }
        cursor.setTexture(cursorTexture);
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