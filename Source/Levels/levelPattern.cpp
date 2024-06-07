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
        std::cout<<"Level created\n";
        time(&start);
        lastMobileEnemy=lastAmmoPack=lastHealthPack=lastArmorPack=lastArmoredEnemy=assasinTransition[0]=assasinTransition[1]=lastCombinedEnemy=start;
        myPlayer = new player;
        myCursor=new cursor;
        myStats=new stats;
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
        bulletFire(event, window);
        spawnEntities(window);
        bulletPoll(window);
        enemyBulletPoll(window);
        collision(window);
        myPlayer->playerRender(window);
        myPlayer->playerMove(event, window);
        myCursor->cursorUpdate(window);
        myStats->statsRender(window, myPlayer->getHealth(), myPlayer->getArmor(), myPlayer->getAmmo(), myPlayer->getScore());
        keysCheck(window);
        return 7;
}

void levelPattern::bulletFire(sf::Event& event, sf::RenderWindow& window){
        if (event.type == sf::Event::MouseButtonPressed && myPlayer->getAmmo()>0 && (bullets.empty() || std::difftime(current, bullets.back().getTime())>0.005)){
                bullets.push_back(bullet());
                bullets.back().refresh();
                bullets.back().bulletSet(window, myPlayer->getPosition(), sf::Mouse::getPosition(window));
                myPlayer->ammoDecrement();
        }
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
        if (mode==0 && myPlayer->getScore()>1000){
                if (!bossSpawned){
                        clearVectors();
                        myPlayer->ammoIncrease(300);
                        myPlayer->armorIncrease(100);
                        myPlayer->healthIncrease(100);
                        bossSpawned=true;
                }
                        
        }
        else {
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
        collisionMobile(&mobileEnemies, window);
        collisionArmored(&armoredEnemies, window);
        collisionAssasin(&combinedEnemies, window);
        collisionAmmo(&ammoPacks, window);
        collisionArmor(&armorPacks, window);
        collisionHealth(&healthPacks, window);
        collisionBoss(window);

}

void levelPattern::bulletPoll(sf::RenderWindow& window){
        if (!bullets.empty() && bullets.begin()->bulletLifeCycle())
                bullets.erase(bullets.begin());
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                bulletPosition=it->getPosition();
                it->bulletMove();
                it->entityDraw(window);
                collisionBullet(&mobileEnemies, 15);
                collisionBullet(&armoredEnemies, 30);
                collisionBullet(&combinedEnemies, 60);
                collisionBulletBoss(1000);
        }
}

void levelPattern::enemyBulletPoll(sf::RenderWindow& window){
        playerPosition=myPlayer->getPosition();
        if (!enemyBullets.empty() && enemyBullets.begin()->bulletLifeCycle())
                enemyBullets.erase(enemyBullets.begin());
        for (auto it=enemyBullets.begin(); it!=enemyBullets.end(); ++it){
                it->bulletMove();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->healthDamage(enemyBulletDamage);
                }
        }
}

void levelPattern::collisionMobile(auto props, sf::RenderWindow& window){
        playerPosition=myPlayer->getPosition();
        for (auto it=props->begin(); it!=props->end(); ++it){
            collides(it, window);   
        }
}

void levelPattern::collisionArmored(auto props, sf::RenderWindow& window){
        for (auto it=props->begin(); it!=props->end(); ++it){
                enemyFiresABullet(it, window);
                collides(it, window);  
        }
}

void levelPattern::collisionAssasin(auto props, sf::RenderWindow& window){
        for (auto it=props->begin(); it!=props->end(); ++it){
                if (std::difftime(current, assasinTransition[1])>assasinInterval[1]){
                        assasinTransition[1]=it->setLowSpeed();
                }
                if (std::difftime(current, assasinTransition[0])>assasinInterval[0]){
                        assasinTransition[0]=it->setHighSpeed();
                }
                enemyFiresABullet(it, window);
                collides(it, window);
        }
}

void levelPattern::collisionBoss(sf::RenderWindow& window){
        if (bossSpawned){
                bossFinal->enemyMove(window, playerPosition);
                bossFinal->entityDraw(window);
                if (std::difftime(current, assasinTransition[1])>assasinInterval[1]){
                        assasinTransition[1]=bossFinal->setLowSpeed();
                }
                if (std::difftime(current, assasinTransition[0])>assasinInterval[0]){
                        assasinTransition[0]=bossFinal->setHighSpeed();
                }
                enemyFiresABullet(bossFinal, window);
                collides(bossFinal, window);
        }
}

void levelPattern::collisionAmmo(auto props, sf::RenderWindow& window){
        for (auto it=props->begin(); it!=props->end(); ++it){
                it->refresh();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->ammoIncrease(it->getAmmo());
                        props->erase(it);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
}

void levelPattern::collisionArmor(auto props, sf::RenderWindow& window){
        for (auto it=props->begin(); it!=props->end(); ++it){
                it->refresh();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->armorIncrease(it->getArmor());
                        props->erase(it);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
}

void levelPattern::collisionHealth(auto props, sf::RenderWindow& window){
        for (auto it=props->begin(); it!=props->end(); ++it){
                it->refresh();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->healthIncrease(it->getHealth());
                        props->erase(it);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
}

void levelPattern::collides(auto it, sf::RenderWindow& window){
    it->enemyMove(window, playerPosition);
    it->entityDraw(window);
    if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
        it->setDamageTime(std::time(&prevDamage));
        myPlayer->healthDamage(it->getDamage());
    }
}
                

void levelPattern::collisionBullet(auto props, int increaseScore){
        for (auto it=props->begin(); it!=props->end(); ++it){
                if (it->collidesWithPlayer(bulletPosition)){
                        it->healthDamage(shootingDamage);
                        if (it->getHealth()<=0){
                                props->erase(it);
                                myPlayer->scoreIncrease(increaseScore);
                                break;
                        }
                }
        }
}

void levelPattern::collisionBulletBoss(int increaseScore){
        if (bossSpawned){
                if (bossFinal->collidesWithPlayer(bulletPosition)){
                        bossFinal->healthDamage(shootingDamage);
                        if (bossFinal->getHealth()<=0){
                                bossDefeated=true;
                                myPlayer->scoreIncrease(increaseScore);
                        }
                }
        }
        
}

void levelPattern::enemyFiresABullet(auto it, sf::RenderWindow& window){
        if (std::difftime(current, it->getLastFired())>enemyFireInterval){
                        it->setFired(current);
                        enemyBullets.push_back(bullet());
                        enemyBullets.back().refresh();
                        enemyBullets.back().bulletSetFloat(window, it->getPosition(), playerPosition);
                }
}
