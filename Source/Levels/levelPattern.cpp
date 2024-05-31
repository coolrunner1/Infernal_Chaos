#include "levelPattern.hpp"

levelPattern::levelPattern(){
        levelInit();
        if (!backgroundTexture.loadFromFile("Sprites/lvl1_bg.png")) {
                std::cerr << "Missing file: Sprites/lvl1_bg.png"<<std::endl;
        }
        mobileInterval=2;
        pickupSpawnInterval=15;
        armoredInterval=5;
        enemyFireInterval=1;
}

levelPattern::levelPattern(std::string path){
        levelInit();
        if (!backgroundTexture.loadFromFile(path)) {
                std::cerr << "Missing file: "<<path<<std::endl;
        }
        mobileInterval=2;
        pickupSpawnInterval=15;
        armoredInterval=5;
        enemyFireInterval=1;
}

int levelPattern::levelRender(sf::Event& event, sf::RenderWindow& window){
        std::time(&current);
        setBackground(window);
        window.setMouseCursorVisible(false);
        if (event.type == sf::Event::MouseButtonPressed && myPlayer->getAmmo()>0 && (bullets.empty() || std::difftime(current, bullets.back().getTime())>0.005)){
                bullets.push_back(bullet());
                bullets.back().refresh();
                bullets.back().bulletSet(window, myPlayer->getPosition(), cursorPosition);
                myPlayer->ammoDecrement();
                //tempFired=true;
        }
        //std::cout<<"current: "<<current<<"last:"<<start<<std::endl;
        if (std::difftime(current, lastMobileEnemy)>mobileInterval){
                mobileEnemies.push_back(enemyMobile());
                lastMobileEnemy=mobileEnemies.back().getTime();
                //bullets.back().bulletSet(window, myPlayer->getPlayerPosition(), cursorPosition);
        }
        if (std::difftime(current, lastArmoredEnemy)>armoredInterval){
                armoredEnemies.push_back(armoredEnemy());
                lastArmoredEnemy=armoredEnemies.back().getTime();
                armoredEnemies.back().setFired(lastArmoredEnemy);
        }
        if (std::difftime(current, lastAmmoPack)>pickupSpawnInterval+15){
                ammoPacks.push_back(ammoPack());
                ammoPacks.back().refresh();
                lastAmmoPack=ammoPacks.back().getTime();
                //ammoPacks.back().entityDraw(window);
        }
        if (std::difftime(current, lastArmorPack)>pickupSpawnInterval+25){
                armorPacks.push_back(armorPack());
                armorPacks.back().refresh();
                lastArmorPack=armorPacks.back().getTime();
                //ammoPacks.back().entityDraw(window);
        }
        if (std::difftime(current, lastHealthPack)>pickupSpawnInterval+20){
                healthPacks.push_back(healthPack());
                healthPacks.back().refresh();
                //healthPacks.back().entityDraw(window);
                lastHealthPack=healthPacks.back().getTime();
                //ammoPacks.back().entityDraw(window);
        }
        /*healthPacks.push_back(healthPack());
        healthPacks.back().refresh();
        healthPacks.back().entityDraw(window);*/
        bulletPoll(window);
        enemyBulletPoll(window);
        //enemyMobilePoll(window);
        collision(window);
        myPlayer->playerRender(window);
        myPlayer->playerMove(event, window);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                while(true){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                                break;
                        }
                }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || myPlayer->getHealth()<=0){
                while(true){
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                                break;
                        }
                }
                delete myPlayer;
                return 0;
        }
        cursorPosition=sf::Mouse::getPosition(window);
        cursor.setPosition(cursorPosition.x-25, cursorPosition.y-25);
        window.draw(cursor);
        return 4;
}

void levelPattern::levelInit(){
        std::cout<<"Level created\n";
        time(&start);
        lastMobileEnemy=lastAmmoPack=lastHealthPack=lastArmorPack=lastArmoredEnemy=start;
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
        for (auto it=mobileEnemies.begin(); it!=mobileEnemies.end(); ++it){
                playerPosition=myPlayer->getPosition();
                propPosition=it->getPosition();
                it->enemyMove(window, playerPosition);
                it->entityDraw(window);
                if (playerPosition.x >= propPosition.x-70 && playerPosition.x <= propPosition.x+70 && playerPosition.y >= propPosition.y-70 && playerPosition.y <= propPosition.y+70 && std::difftime(current, it->getDamageTime())>0.05){
                        it->setDamageTime(std::time(&prevDamage));
                        myPlayer->healthDamage(it->getDamage());
                }
        }
        for (auto it=armoredEnemies.begin(); it!=armoredEnemies.end(); ++it){
                playerPosition=myPlayer->getPosition();
                if (std::difftime(current, it->getLastFired())>enemyFireInterval){
                        it->setFired(current);
                        enemyBullets.push_back(bullet());
                        enemyBullets.back().bulletSetFloat(window, it->getPosition(), playerPosition);
                }
                propPosition=it->getPosition();
                it->enemyMove(window, playerPosition);
                it->entityDraw(window);
                if (playerPosition.x >= propPosition.x-70 && playerPosition.x <= propPosition.x+70 && playerPosition.y >= propPosition.y-70 && playerPosition.y <= propPosition.y+70 && std::difftime(current, it->getDamageTime())>0.05){
                        it->setDamageTime(std::time(&prevDamage));
                        myPlayer->healthDamage(it->getDamage());
                }
        }
        for (auto ammoPack=ammoPacks.begin(); ammoPack!=ammoPacks.end(); ++ammoPack){
                propPosition=ammoPack->getPosition();
                ammoPack->entityDraw(window);
                if (playerPosition.x >= propPosition.x-70 && playerPosition.x <= propPosition.x+70 && playerPosition.y >= propPosition.y-70 && playerPosition.y <= propPosition.y+70){
                        myPlayer->ammoIncrease(ammoPack->getAmmo());
                        ammoPacks.erase(ammoPack);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
        for (auto armorPack=armorPacks.begin(); armorPack!=armorPacks.end(); ++armorPack){
                propPosition=armorPack->getPosition();
                armorPack->entityDraw(window);
                if (playerPosition.x >= propPosition.x-70 && playerPosition.x <= propPosition.x+70 && playerPosition.y >= propPosition.y-70 && playerPosition.y <= propPosition.y+70){
                        myPlayer->armorIncrease(armorPack->getArmor());
                        armorPacks.erase(armorPack);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
        for (auto healthPack=healthPacks.begin(); healthPack!=healthPacks.end(); ++healthPack){
                propPosition=healthPack->getPosition();
                healthPack->entityDraw(window);
                if (playerPosition.x >= propPosition.x-70 && playerPosition.x <= propPosition.x+70 && playerPosition.y >= propPosition.y-70 && playerPosition.y <= propPosition.y+70){
                        myPlayer->healthIncrease(healthPack->getHealth());
                        healthPacks.erase(healthPack);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
        //temp.entityDraw(window);
}

void levelPattern::bulletPoll(sf::RenderWindow& window){
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                if (it->bulletLifeCycle()){
                        bullets.erase(it);
                        break;
                }
                else{
                        it->bulletMove();
                        it->entityDraw(window);
                }
                for (auto mobileEnemy=mobileEnemies.begin(); mobileEnemy!=mobileEnemies.end(); ++mobileEnemy){
                        bulletPosition=it->getPosition();
                        propPosition=mobileEnemy->getPosition();
                        //mobileEnemy->enemyMove(window, playerPosition);
                        //mobileEnemy->entityDraw(window);
                        if (bulletPosition.x >= propPosition.x-70 && bulletPosition.x <= propPosition.x+70 && bulletPosition.y >= propPosition.y-70 && bulletPosition.y <= propPosition.y+70){
                                mobileEnemy->healthDamage(1000);
                                if (mobileEnemy->getHealth()<=0){
                                        mobileEnemies.erase(mobileEnemy);
                                        myPlayer->scoreIncrease(15);
                                        break;
                                }
                        }
                }
                for (auto armoredEnemy=armoredEnemies.begin(); armoredEnemy!=armoredEnemies.end(); ++armoredEnemy){
                        bulletPosition=it->getPosition();
                        propPosition=armoredEnemy->getPosition();
                        //mobileEnemy->enemyMove(window, playerPosition);
                        //mobileEnemy->entityDraw(window);
                        if (bulletPosition.x >= propPosition.x-70 && bulletPosition.x <= propPosition.x+70 && bulletPosition.y >= propPosition.y-70 && bulletPosition.y <= propPosition.y+70){
                                armoredEnemy->healthDamage(1000);
                                if (armoredEnemy->getHealth()<=0){
                                        armoredEnemies.erase(armoredEnemy);
                                        myPlayer->scoreIncrease(30);
                                        break;
                                }
                        }
                }
        }
}

void levelPattern::enemyBulletPoll(sf::RenderWindow& window){
        for (auto it=enemyBullets.begin(); it!=enemyBullets.end(); ++it){
                if (it->bulletLifeCycle()){
                        enemyBullets.erase(it);
                        break;
                }
                else{
                        it->bulletMove();
                        it->entityDraw(window);
                }
                bulletPosition=it->getPosition();
                propPosition=myPlayer->getPosition();
                if (bulletPosition.x >= propPosition.x-70 && bulletPosition.x <= propPosition.x+70 && bulletPosition.y >= propPosition.y-70 && bulletPosition.y <= propPosition.y+70){
                        myPlayer->healthDamage(2);
                }
        }
}

/*player* sprt = new player;
sprt->entityDraw(window);
        sprt->playerMove(event, window);*/