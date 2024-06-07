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
        bossFinal=new boss();
        bossDefeated=false;
        bossSpawned=false;
        //bossFinal=NULL;
        std::cout<<"Level created\n";
        time(&start);
        lastMobileEnemy=lastAmmoPack=lastHealthPack=lastArmorPack=lastArmoredEnemy=assasinTransition[0]=assasinTransition[1]=lastCombinedEnemy=start;
        myPlayer = new player;
        myCursor=new cursor;
}

void levelPattern::setEasyDifficulty(){
        mobileInterval=2;
        pickupSpawnInterval=15;
        armoredInterval=5;
        enemyFireInterval=1;
        assasinInterval[0]=5;
        assasinInterval[1]=0.5;
        assasinSpawnInterval=30;
        shootingDamage=3;
        enemyBulletDamage=1;
        mode=1;
}

void levelPattern::setMediumDifficulty(){
        mobileInterval=1;
        pickupSpawnInterval=25;
        armoredInterval=3;
        enemyFireInterval=0.5;
        assasinInterval[0]=4;
        assasinInterval[1]=0.5;
        assasinSpawnInterval=15;
        shootingDamage=2;
        enemyBulletDamage=2;
        mode=2;
}

void levelPattern::setHardDifficulty(){
        mobileInterval=0.5;
        pickupSpawnInterval=35;
        armoredInterval=1;
        enemyFireInterval=0.1;
        assasinInterval[0]=2;
        assasinInterval[1]=0.5;
        assasinSpawnInterval=5;
        shootingDamage=1;
        enemyBulletDamage=3;
        mode=3;
}

void levelPattern::setCampaign(){
        setEasyDifficulty();
        mode=0;
        
}

int levelPattern::levelRender(sf::Event& event, sf::RenderWindow& window){
        std::time(&current);
        setBackground(window);
        window.setMouseCursorVisible(false);
        if (event.type == sf::Event::MouseButtonPressed && myPlayer->getAmmo()>0 && (bullets.empty() || std::difftime(current, bullets.back().getTime())>0.005)){
                bullets.push_back(bullet());
                bullets.back().refresh();
                bullets.back().bulletSet(window, myPlayer->getPosition(), sf::Mouse::getPosition(window));
                myPlayer->ammoDecrement();
        }
        if (mode==0 && myPlayer->getScore()>1000){
                if (!bossSpawned){
                        clearVectors();
                        myPlayer->ammoIncrease(300);
                        myPlayer->armorIncrease(100);
                        myPlayer->healthIncrease(100);
                        bossSpawned=true;
                }
                        
        }
        else{
             spawnEntities(window); 
        }
        bulletPoll(window);
        enemyBulletPoll(window);
        collision(window);
        myPlayer->playerRender(window);
        myPlayer->playerMove(event, window);
        
        myCursor->cursorUpdate(window);
        keysCheck(window);
        return 7;
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

void levelPattern::spawnEntities(sf::RenderWindow& window){
        if (std::difftime(current, lastMobileEnemy)>mobileInterval){
                mobileEnemies.push_back(enemyMobile());
                lastMobileEnemy=mobileEnemies.back().getTime();
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
        }
        if (std::difftime(current, lastArmorPack)>pickupSpawnInterval+25){
                armorPacks.push_back(armorPack());
                armorPacks.back().refresh();
                lastArmorPack=armorPacks.back().getTime();
        }
        if (std::difftime(current, lastHealthPack)>pickupSpawnInterval+20){
                healthPacks.push_back(healthPack());
                healthPacks.back().refresh();
                lastHealthPack=healthPacks.back().getTime();
        }
        if (std::difftime(current, lastCombinedEnemy)>assasinSpawnInterval){
                combinedEnemies.push_back(combinedEnemy());
                lastCombinedEnemy=combinedEnemies.back().getTime();
                combinedEnemies.back().setFired(lastCombinedEnemy);
        }
}

void levelPattern::clearVectors(){
        bullets.clear();
        enemyBullets.clear();
        mobileEnemies.clear();
        armoredEnemies.clear();
        combinedEnemies.clear();
        ammoPacks.clear();
        armorPacks.clear();
        healthPacks.clear();
}

levelPattern::~levelPattern(){
        clearVectors();
        delete myPlayer;
        delete bossFinal;
        delete stillScreens;
}

void levelPattern::setBackground(sf::RenderWindow& window){
        backgroundShape.setTexture(backgroundTexture);
        window.draw(backgroundShape);
}

void levelPattern::collision(sf::RenderWindow& window){
        playerPosition=myPlayer->getPosition();
        for (auto it=mobileEnemies.begin(); it!=mobileEnemies.end(); ++it){
                it->enemyMove(window, playerPosition);
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
                        it->setDamageTime(std::time(&prevDamage));
                        myPlayer->healthDamage(it->getDamage());
                }
        }
        for (auto it=armoredEnemies.begin(); it!=armoredEnemies.end(); ++it){
                if (std::difftime(current, it->getLastFired())>enemyFireInterval){
                        it->setFired(current);
                        enemyBullets.push_back(bullet());
                        enemyBullets.back().refresh();
                        enemyBullets.back().bulletSetFloat(window, it->getPosition(), playerPosition);
                }
                it->enemyMove(window, playerPosition);
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
                        it->setDamageTime(std::time(&prevDamage));
                        myPlayer->healthDamage(it->getDamage());
                }
        }
        for (auto it=combinedEnemies.begin(); it!=combinedEnemies.end(); ++it){
                if (std::difftime(current, assasinTransition[1])>assasinInterval[1]){
                        assasinTransition[1]=it->setLowSpeed();
                }
                if (std::difftime(current, assasinTransition[0])>assasinInterval[0]){
                        assasinTransition[0]=it->setHighSpeed();
                }
                if (std::difftime(current, it->getLastFired())>enemyFireInterval){
                        it->setFired(current);
                        enemyBullets.push_back(bullet());
                        enemyBullets.back().refresh();
                        enemyBullets.back().bulletSetFloat(window, it->getPosition(), playerPosition);
                }
                it->enemyMove(window, playerPosition);
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
                        it->setDamageTime(std::time(&prevDamage));
                        myPlayer->healthDamage(it->getDamage());
                }
        }
        for (auto ammoPack=ammoPacks.begin(); ammoPack!=ammoPacks.end(); ++ammoPack){
                ammoPack->entityDraw(window);
                if (ammoPack->collidesWithPlayer(playerPosition)){
                        myPlayer->ammoIncrease(ammoPack->getAmmo());
                        ammoPacks.erase(ammoPack);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
        for (auto armorPack=armorPacks.begin(); armorPack!=armorPacks.end(); ++armorPack){
                armorPack->entityDraw(window);
                if (armorPack->collidesWithPlayer(playerPosition)){
                        myPlayer->armorIncrease(armorPack->getArmor());
                        armorPacks.erase(armorPack);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
        for (auto healthPack=healthPacks.begin(); healthPack!=healthPacks.end(); ++healthPack){
                healthPack->entityDraw(window);
                if (healthPack->collidesWithPlayer(playerPosition)){
                        myPlayer->healthIncrease(healthPack->getHealth());
                        healthPacks.erase(healthPack);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
        if (bossSpawned){
                if (std::difftime(current, assasinTransition[1])>assasinInterval[1]){
                        assasinTransition[1]=bossFinal->setLowSpeed();
                }
                if (std::difftime(current, assasinTransition[0])>assasinInterval[0]){
                        assasinTransition[0]=bossFinal->setHighSpeed();
                }
                if (std::difftime(current, bossFinal->getLastFired())>enemyFireInterval){
                        bossFinal->setFired(current);
                        enemyBullets.push_back(bullet());
                        enemyBullets.back().refresh();
                        enemyBullets.back().bulletSetFloat(window, bossFinal->getPosition(), playerPosition);
                }
                bossFinal->enemyMove(window, playerPosition);
                bossFinal->entityDraw(window);
                if (bossFinal->collidesWithPlayer(playerPosition) && std::difftime(current, bossFinal->getDamageTime())>0.05){
                        bossFinal->setDamageTime(std::time(&prevDamage));
                        myPlayer->healthDamage(bossFinal->getDamage());
                }
        }

}

void levelPattern::bulletPoll(sf::RenderWindow& window){
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                bulletPosition=it->getPosition();
                if (it->bulletLifeCycle()){
                        bullets.erase(it);
                        break;
                }
                else{
                        it->bulletMove();
                        it->entityDraw(window);
                }
                for (auto mobileEnemy=mobileEnemies.begin(); mobileEnemy!=mobileEnemies.end(); ++mobileEnemy){
                        if (mobileEnemy->collidesWithPlayer(bulletPosition)){
                                mobileEnemy->healthDamage(shootingDamage);
                                if (mobileEnemy->getHealth()<=0){
                                        mobileEnemies.erase(mobileEnemy);
                                        myPlayer->scoreIncrease(15);
                                        break;
                                }
                        }
                }
                for (auto armoredEnemy=armoredEnemies.begin(); armoredEnemy!=armoredEnemies.end(); ++armoredEnemy){
                        if (armoredEnemy->collidesWithPlayer(bulletPosition)){
                                armoredEnemy->healthDamage(shootingDamage);
                                if (armoredEnemy->getHealth()<=0){
                                        armoredEnemies.erase(armoredEnemy);
                                        myPlayer->scoreIncrease(30);
                                        break;
                                }
                        }
                }
                for (auto combinedEnemy=combinedEnemies.begin(); combinedEnemy!=combinedEnemies.end(); ++combinedEnemy){
                        if (combinedEnemy->collidesWithPlayer(bulletPosition)){
                                combinedEnemy->healthDamage(shootingDamage);
                                if (combinedEnemy->getHealth()<=0){
                                        combinedEnemies.erase(combinedEnemy);
                                        myPlayer->scoreIncrease(60);
                                        break;
                                }
                        }
                }
                if (bossSpawned){
                        if (bossFinal->collidesWithPlayer(bulletPosition)){
                                bossFinal->healthDamage(shootingDamage);
                                if (bossFinal->getHealth()<=0){
                                        bossDefeated=true;
                                        myPlayer->scoreIncrease(1000);
                                        break;
                                }
                        }
                }
        }
}

void levelPattern::enemyBulletPoll(sf::RenderWindow& window){
        playerPosition=myPlayer->getPosition();
        for (auto it=enemyBullets.begin(); it!=enemyBullets.end(); ++it){
                if (it->bulletLifeCycle()){
                        enemyBullets.erase(it);
                        break;
                }
                else{
                        it->bulletMove();
                        it->entityDraw(window);
                }
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->healthDamage(enemyBulletDamage);
                }
        }
}