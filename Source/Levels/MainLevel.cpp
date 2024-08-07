#include "MainLevel.hpp"

MainLevel::MainLevel() : LevelPattern("Sprites/lvl1_bg.png"){
    bossFinal=new Boss();
    lastMobileEnemy=lastAmmoPack=lastHealthPack=lastArmorPack=lastArmoredEnemy=assasinTransition[0]=assasinTransition[1]=lastCombinedEnemy=start;
}

MainLevel::~MainLevel(){
    clearVectors();
    delete bossFinal;
}

void MainLevel::spawnEntities(sf::RenderWindow& window){
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
                        mobileEnemies.push_back(EnemyMobile());
                        lastMobileEnemy=mobileEnemies.back().getTime();
                }
                if (std::difftime(current, lastArmoredEnemy)>armoredInterval){
                        armoredEnemies.push_back(ArmoredEnemy());
                        lastArmoredEnemy=armoredEnemies.back().getTime();
                        armoredEnemies.back().setFired(lastArmoredEnemy);
                }
                if (std::difftime(current, lastAmmoPack)>pickupSpawnInterval+15){
                        ammoPacks.push_back(AmmoPack());
                        ammoPacks.back().refresh();
                        lastAmmoPack=ammoPacks.back().getTime();
                }
                if (std::difftime(current, lastArmorPack)>pickupSpawnInterval+25){
                        armorPacks.push_back(ArmorPack());
                        armorPacks.back().refresh();
                        lastArmorPack=armorPacks.back().getTime();
                }
                if (std::difftime(current, lastHealthPack)>pickupSpawnInterval+20){
                        healthPacks.push_back(HealthPack());
                        healthPacks.back().refresh();
                        lastHealthPack=healthPacks.back().getTime();
                }
                if (std::difftime(current, lastCombinedEnemy)>assasinSpawnInterval){
                        combinedEnemies.push_back(CombinedEnemy());
                        lastCombinedEnemy=combinedEnemies.back().getTime();
                        combinedEnemies.back().setFired(lastCombinedEnemy);
                }
        }
        
}

void MainLevel::bulletPoll(sf::RenderWindow& window){
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

void MainLevel::collision(sf::RenderWindow& window){
        playerPosition=myPlayer->getPosition();
        collisionMobile(window);
        collisionArmored(window);
        collisionAssasin(window);
        collisionAmmo(window);
        collisionArmor(window);
        collisionHealth(window);
        collisionBoss(window);

}

void MainLevel::clearVectors(){
        bullets.clear();
        enemyBullets.clear();
        mobileEnemies.clear();
        armoredEnemies.clear();
        combinedEnemies.clear();
        ammoPacks.clear();
        armorPacks.clear();
        healthPacks.clear();
}


void MainLevel::setEasyDifficulty(){
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

void MainLevel::setMediumDifficulty(){
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

void MainLevel::setHardDifficulty(){
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

void MainLevel::setCampaign(){
        setEasyDifficulty();
        mode=0;
}

void MainLevel::collisionBoss(sf::RenderWindow& window){
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
                collidesBoss(window);
        }
}

void MainLevel::collisionBulletBoss(int increaseScore){
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

void MainLevel::collisionAssasin(sf::RenderWindow& window){
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

int MainLevel::levelRender(sf::Event& event, sf::RenderWindow& window){
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

void MainLevel::collisionBullet(auto props, int increaseScore){
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

void MainLevel::collisionMobile(sf::RenderWindow& window){
        playerPosition=myPlayer->getPosition();
        for (auto it=mobileEnemies.begin(); it!=mobileEnemies.end(); ++it){
            collides(it, window);   
        }
}

void MainLevel::collisionArmored(sf::RenderWindow& window){
        for (auto it=armoredEnemies.begin(); it!=armoredEnemies.end(); ++it){
                enemyFiresABullet(it, window);
                collides(it, window);  
        }
}

void MainLevel::enemyFiresABullet(auto it, sf::RenderWindow& window){
        if (std::difftime(current, it->getLastFired())>enemyFireInterval){
                        it->setFired(current);
                        enemyBullets.push_back(Bullet());
                        enemyBullets.back().refresh();
                        enemyBullets.back().bulletSetFloat(window, it->getPosition(), playerPosition);
                }
}

void MainLevel::collidesBoss(sf::RenderWindow& window){
    bossFinal->enemyMove(window, playerPosition);
    bossFinal->entityDraw(window);
    if (bossFinal->collidesWithPlayer(playerPosition) && std::difftime(current, bossFinal->getDamageTime())>0.05){
        bossFinal->setDamageTime(std::time(&prevDamage));
        myPlayer->healthDamage(bossFinal->getDamage());
    }
}

void MainLevel::enemyBulletPoll(sf::RenderWindow& window){
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

void MainLevel::collisionAmmo(sf::RenderWindow& window){
        for (auto it=ammoPacks.begin(); it!=ammoPacks.end(); ++it){
                it->refresh();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->ammoIncrease(it->getAmmo());
                        ammoPacks.erase(it);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
}

void MainLevel::collisionArmor(sf::RenderWindow& window){
        for (auto it=armorPacks.begin(); it!=armorPacks.end(); ++it){
                it->refresh();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->armorIncrease(it->getArmor());
                        armorPacks.erase(it);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
}

void MainLevel::collisionHealth(sf::RenderWindow& window){
        for (auto it=healthPacks.begin(); it!=healthPacks.end(); ++it){
                it->refresh();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->healthIncrease(it->getHealth());
                        healthPacks.erase(it);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
}

void MainLevel::collides(auto it, sf::RenderWindow& window){
    it->enemyMove(window, playerPosition);
    it->entityDraw(window);
    if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
        it->setDamageTime(std::time(&prevDamage));
        myPlayer->healthDamage(it->getDamage());
    }
}

void MainLevel::bulletFire(sf::Event& event, sf::RenderWindow& window){
        if (event.type == sf::Event::MouseButtonPressed && myPlayer->getAmmo()>0 && (bullets.empty() || std::difftime(current, bullets.back().getTime())>0.005)){
                bullets.push_back(Bullet());
                bullets.back().refresh();
                bullets.back().bulletSet(window, myPlayer->getPosition(), sf::Mouse::getPosition(window));
                myPlayer->ammoDecrement();
        }
}