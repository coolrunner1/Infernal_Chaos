#include "levelPattern.hpp"

levelPattern::levelPattern(){
        levelInit();
        if (!backgroundTexture.loadFromFile("Sprites/lvl1_bg.png")) {
                std::cerr << "Missing file: Sprites/lvl1_bg.png"<<std::endl;
        }
        mobileInterval=3;
        time(&start);
}

levelPattern::levelPattern(std::string path){
        levelInit();
        if (!backgroundTexture.loadFromFile(path)) {
                std::cerr << "Missing file: "<<path<<std::endl;
        }
        mobileInterval=3;
        pickupSpawnInterval=15; 
}

void levelPattern::levelRender(sf::Event& event, sf::RenderWindow& window){
        std::time(&current);
        setBackground(window);
        window.setMouseCursorVisible(false);
        if (event.type == sf::Event::MouseButtonPressed && myPlayer->getAmmo()>0 && (bullets.empty() || std::difftime(current, bullets.back().getTime())>0.005)){
                bullets.push_back(bullet());
                bullets.back().bulletSet(window, myPlayer->getPosition(), cursorPosition);
                myPlayer->ammoDecrement();
                //tempFired=true;
        }
        if (std::difftime(current, start)>2 && (mobileEnemies.empty() || std::difftime(current, mobileEnemies.back().getTime())>mobileInterval)){
                mobileEnemies.push_back(enemyMobile());
                //bullets.back().bulletSet(window, myPlayer->getPlayerPosition(), cursorPosition);
        }
        /*if (tempFired){
                tempBul->bulletMove(tempBulletReachedEnd);
                window.draw(tempBul->entitySprite);
        }*/
        /*if (tempBulletReachedEnd){
                tempBulletReachedEnd=false;  
                tempFired=false;

        }*/
        /*if (std::difftime(current, start)>30 && (ammoPacks.empty() || ammoPacks.back().getTime()>pickupSpawnInterval)){
                ammoPacks.push_back(ammoPack());
                ammoPacks.back().entityDraw(window);
        }*/
        bulletPoll(window);
        //enemyMobilePoll(window);
        collision(window);
        myPlayer->playerRender(window);
        myPlayer->playerMove(event, window);
        cursorPosition=sf::Mouse::getPosition(window);
        cursor.setPosition(cursorPosition.x-25, cursorPosition.y-25);
        window.draw(cursor);
}

void levelPattern::levelInit(){
        std::cout<<"Level created\n";
        myPlayer = new player;
        if (!cursorTexture.loadFromFile("Sprites/Cursor.png")) {
                std::cerr << "Missing file: Sprites/Cursor.png"<<std::endl;
        }
        cursor.setTexture(cursorTexture);
        cursor.setScale(3, 3);
}

levelPattern::~levelPattern(){
        bullets.clear();
        mobileEnemies.clear();
        delete myPlayer;
}

void levelPattern::setBackground(sf::RenderWindow& window){
        backgroundShape.setTexture(backgroundTexture);
        window.draw(backgroundShape);
}

void levelPattern::collision(sf::RenderWindow& window){
        if (!mobileEnemies.empty()){
                for (auto it=mobileEnemies.begin(); it!=mobileEnemies.end(); ++it){
                        playerPosition=myPlayer->getPosition();
                        enemyPosition=it->getPosition();
                        it->enemyMove(window, playerPosition);
                        it->entityDraw(window);
                        if (playerPosition.x >= enemyPosition.x-70 && playerPosition.x <= enemyPosition.x+70 && playerPosition.y >= enemyPosition.y-70 && playerPosition.y <= enemyPosition.y+70 && std::difftime(current, prevDamage)>0.005){
                                std::time(&prevDamage);
                                myPlayer->healthDamage(it->getDamage());
                        }
                }
        }
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
                        it->bulletMove();
                        it->entityDraw(window);
                }
                ++bulletNum;
        }
}

void levelPattern::enemyMobilePoll(sf::RenderWindow& window){
        //bulletNum=0;
        for (auto it=mobileEnemies.begin(); it!=mobileEnemies.end(); ++it){
                it->enemyMove(window, myPlayer->getPosition());
                it->entityDraw(window);
                /*if (bullets[bulletNum].bulletLifeCycle()){
                        bullets.erase(it);
                        if (bulletNum>=bullets.size())
                                break;
                }
                else{
                        bullets[bulletNum].bulletMove();
                        bullets[bulletNum].entityDraw(window);
                }
                ++bulletNum;
                }*/
        }
}

/*player* sprt = new player;
sprt->entityDraw(window);
        sprt->playerMove(event, window);*/