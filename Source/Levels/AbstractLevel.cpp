#include "AbstractLevel.hpp"

AbstractLevel::AbstractLevel(){
        levelInit();
        if (!backgroundTexture.loadFromFile("Sprites/lvl1_bg.png")) {
                std::cerr << "Missing file: Sprites/lvl1_bg.png"<<std::endl;
        }
}

AbstractLevel::AbstractLevel(std::string path){
        levelInit();
        if (!backgroundTexture.loadFromFile(path)) {
                std::cerr << "Missing file: " << path << std::endl;
        }
}

void AbstractLevel::levelInit(){
        stillScreens = new StillScreen;
        bossDefeated = false;
        bossSpawned = false;
        std::cout << "Level created\n";
        enemyBulletDamage = 1;
        player = new Player;
        cursor = new Cursor;
        stats = new Stats;
}


void AbstractLevel::keysCheck(sf::RenderWindow& window){
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

AbstractLevel::~AbstractLevel(){
        delete player;
        delete stillScreens;
        delete cursor;
        delete stats;
}

void AbstractLevel::setBackground(std::string background) {
        if (!backgroundTexture.loadFromFile(background)) {
                std::cerr << "Missing file: " << background <<std::endl;
        }
}

void AbstractLevel::refreshBackground(sf::RenderWindow& window){
        backgroundShape.setTexture(backgroundTexture);
        window.draw(backgroundShape);
}