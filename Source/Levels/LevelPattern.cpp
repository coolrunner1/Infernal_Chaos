#include "LevelPattern.hpp"

LevelPattern::LevelPattern(){
        levelInit();
        if (!backgroundTexture.loadFromFile("Sprites/lvl1_bg.png")) {
                std::cerr << "Missing file: Sprites/lvl1_bg.png"<<std::endl;
        }
}

LevelPattern::LevelPattern(std::string path){
        levelInit();
        if (!backgroundTexture.loadFromFile(path)) {
                std::cerr << "Missing file: "<<path<<std::endl;
        }
}

void LevelPattern::levelInit(){
        stillScreens=new StillScreen;
        bossDefeated=false;
        bossSpawned=false;
        std::cout<<"Level created\n";
        time(&start);
        enemyBulletDamage=1;
        player = new Player;
        cursor=new Cursor;
        stats=new Stats;
}


void LevelPattern::keysCheck(sf::RenderWindow& window){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                stillScreens->pause(window);
                while(true){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                                break;
                        }
                }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || player->getHealth()<=0){
                stillScreens->gameOver(window);
                while(true){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                                break;
                        }
                }
                delete player;
                window.close();
        }
        if (bossDefeated){
                stillScreens->youWin(window);
                while(true){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                                break;
                        }
                }
                delete player;
                window.close();
        }
}

LevelPattern::~LevelPattern(){
        delete player;
        delete stillScreens;
        delete cursor;
        delete stats;
}

void LevelPattern::setBackground(sf::RenderWindow& window){
        backgroundShape.setTexture(backgroundTexture);
        window.draw(backgroundShape);
}