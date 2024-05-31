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
        std::time(&current);
        setBackground(window);
        window.setMouseCursorVisible(false);
        test->entityDraw(window);
        test->enemyMove(window, myPlayer->getPlayerPosition());
        myPlayer->playerRender(window);
        myPlayer->playerMove(event, window);
        cursorPosition=sf::Mouse::getPosition(window);
        cursor.setPosition(cursorPosition.x-25, cursorPosition.y-25);
        window.draw(cursor);
        if (event.type == sf::Event::MouseButtonPressed && myPlayer->getAmmo()>0 && (bullets.empty() || std::difftime(current, bullets.back().getTime())>0.005)){
                bullets.push_back(bullet());
                bullets.back().bulletSet(window, myPlayer->getPlayerPosition(), cursorPosition);
                myPlayer->ammoDecrement();
                //tempFired=true;
        }
        /*if (tempFired){
                tempBul->bulletMove(tempBulletReachedEnd);
                window.draw(tempBul->entitySprite);
        }*/
        /*if (tempBulletReachedEnd){
                tempBulletReachedEnd=false;  
                tempFired=false;

        }*/
        bulletPoll(window);
}

void levelPattern::levelInit(){
        std::cout<<"Level created\n";
        myPlayer = new player;
        test=new enemyMobile;
        if (!cursorTexture.loadFromFile("Sprites/Cursor.png")) {
                std::cerr << "Missing file: Sprites/Cursor.png"<<std::endl;
        }
        cursor.setTexture(cursorTexture);
        cursor.setScale(3, 3);
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

void levelPattern::bulletPoll(sf::RenderWindow& window){
        bulletNum=0;
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                if (bullets[bulletNum].bulletLifeCycle()){
                        bullets.erase(it);
                        if (bulletNum>=bullets.size())
                                break;
                }
                else{
                        bullets[bulletNum].bulletMove();
                        bullets[bulletNum].entityDraw(window);
                }
                ++bulletNum;
        }
}

/*player* sprt = new player;
sprt->entityDraw(window);
        sprt->playerMove(event, window);*/