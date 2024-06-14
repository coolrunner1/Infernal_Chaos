#include "mainLevel.hpp"

mainLevel::mainLevel() : levelPattern("Sprites/lvl1_bg.png"){
    bossContainerPoint=new bossContainer();
    mobileEnemiesContainer=new mobileContainer();
    armoredEnemiesContainer=new armoredContainer();
    ammoPacksContainer=new ammoPackContainer();
    armorPacksContainer=new armorPackContainer();
    healthPacksContainer=new healthPackContainer();
    lastMobileEnemy=lastAmmoPack=lastHealthPack=lastArmorPack=lastArmoredEnemy=assasinTransition[0]=assasinTransition[1]=lastCombinedEnemy=start;
}

mainLevel::~mainLevel(){
    clearVectors();
    delete bossContainerPoint;
}

void mainLevel::spawnEntities(sf::RenderWindow& window){
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
                        lastMobileEnemy=mobileEnemiesContainer->pushEnemy();
                }
                if (std::difftime(current, lastArmoredEnemy)>armoredInterval){
                        lastArmoredEnemy=armoredEnemiesContainer->pushEnemy();
                }
                if (std::difftime(current, lastAmmoPack)>pickupSpawnInterval+15){
                        lastAmmoPack=ammoPacksContainer->pushPack();
                }
                if (std::difftime(current, lastArmorPack)>pickupSpawnInterval+25){
                        lastArmorPack=armorPacksContainer->pushPack();
                }
                if (std::difftime(current, lastHealthPack)>pickupSpawnInterval+20){
                        lastHealthPack=healthPacksContainer->pushPack();
                }
                if (std::difftime(current, lastCombinedEnemy)>assasinSpawnInterval){
                        combinedEnemies.push_back(combinedEnemy());
                        lastCombinedEnemy=combinedEnemies.back().getTime();
                        combinedEnemies.back().setFired(lastCombinedEnemy);
                }
        }
        
}

void mainLevel::bulletPoll(sf::RenderWindow& window){
        if (!bullets.empty() && bullets.begin()->bulletLifeCycle())
                bullets.erase(bullets.begin());
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                bulletPosition=it->getPosition();
                it->bulletMove();
                it->entityDraw(window);
                mobileEnemiesContainer->collisionBullet(15, bulletPosition, shootingDamage, myPlayer);
                armoredEnemiesContainer->collisionBullet(30, bulletPosition, shootingDamage, myPlayer);
                collisionBullet(&combinedEnemies, 60);
                bossDefeated=bossContainerPoint->collisionBulletBoss(1000, bossSpawned, bulletPosition, shootingDamage, myPlayer);
        }
}

void mainLevel::collision(sf::RenderWindow& window){
        playerPosition=myPlayer->getPosition();
        mobileEnemiesContainer->collisionMobile(window, current, myPlayer, &prevDamage);
        armoredEnemiesContainer->collisionArmored(window, current, playerPosition, &enemyBullets, myPlayer, &prevDamage, enemyFireInterval);
        collisionAssasin(window);
        ammoPacksContainer->collisionAmmo(window, myPlayer, playerPosition);
        armorPacksContainer->collisionArmor(window, myPlayer, playerPosition);
        healthPacksContainer->collisionHealth(window, myPlayer, playerPosition);
        bossContainerPoint->collisionBoss(window, bossSpawned, &assasinTransition[0], &assasinTransition[1], assasinInterval, current, playerPosition, &enemyBullets, myPlayer, &prevDamage, enemyFireInterval);

}

void mainLevel::clearVectors(){
        bullets.clear();
        enemyBullets.clear();
        mobileEnemiesContainer->clearVector();
        armoredEnemiesContainer->clearVector();
        combinedEnemies.clear();
        ammoPacksContainer->clearVector();
        armorPacksContainer->clearVector();
        healthPacksContainer->clearVector();
}


void mainLevel::setEasyDifficulty(){
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

void mainLevel::setMediumDifficulty(){
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

void mainLevel::setHardDifficulty(){
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

void mainLevel::setCampaign(){
        setEasyDifficulty();
        mode=0;
}

void mainLevel::collisionAssasin(sf::RenderWindow& window){
        for (auto it=combinedEnemies.begin(); it!=combinedEnemies.end(); ++it){
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

int mainLevel::levelRender(sf::Event& event, sf::RenderWindow& window){
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

void mainLevel::collisionBullet(auto props, int increaseScore){
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


void mainLevel::enemyFiresABullet(auto it, sf::RenderWindow& window){
        if (std::difftime(current, it->getLastFired())>enemyFireInterval){
                        it->setFired(current);
                        enemyBullets.push_back(bullet());
                        enemyBullets.back().refresh();
                        enemyBullets.back().bulletSetFloat(window, it->getPosition(), playerPosition);
                }
}

void mainLevel::enemyBulletPoll(sf::RenderWindow& window){
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

void mainLevel::collides(auto it, sf::RenderWindow& window){
    it->enemyMove(window, playerPosition);
    it->entityDraw(window);
    if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
        it->setDamageTime(std::time(&prevDamage));
        myPlayer->healthDamage(it->getDamage());
    }
}

