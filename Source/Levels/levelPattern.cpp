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

void levelPattern::levelInit(){
        stillScreens=new stillScreen;
        bossDefeated=false;
        bossSpawned=false;
        std::cout<<"Level created\n";
        time(&start);
        enemyBulletDamage=1;
        myPlayer = new player;
        myCursor=new cursor;
        myStats=new stats;
}


void levelPattern::keysCheck(sf::RenderWindow& window){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                stillScreens->pause(window);
                while(true){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                                break;
                        }
                }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || myPlayer->getHealth()<=0){
                stillScreens->gameOver(window);
                while(true){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                                break;
                        }
                }
                delete myPlayer;
                window.close();
        }
        if (bossDefeated){
                stillScreens->youWin(window);
                while(true){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                                break;
                        }
                }
                delete myPlayer;
                window.close();
        }
}

levelPattern::~levelPattern(){
        delete myPlayer;
        delete stillScreens;
        delete myCursor;
        delete myStats;
}

void levelPattern::setBackground(sf::RenderWindow& window){
        backgroundShape.setTexture(backgroundTexture);
        window.draw(backgroundShape);
}