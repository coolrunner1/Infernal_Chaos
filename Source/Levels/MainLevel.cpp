#include "MainLevel.hpp"

MainLevel::MainLevel() : AbstractLevel("Sprites/lvl1_bg.png"){
    boss = new Boss();
    lastHealthPack=lastArmorPack=lastArmoredEnemy=assasinTransition[0]=assasinTransition[1]=lastCombinedEnemy=start;
    mobileEnemies = new MobileEnemiesContainer(start);
    ammoPacks = new AmmoPacksContainer(start);
    armorPacks = new ArmorPacksContainer(start);
    healthPacks = new HealthPacksContainer(start);
}

MainLevel::~MainLevel(){
    clearVectors();
    delete mobileEnemies;
    delete ammoPacks;
    delete armorPacks;
    delete healthPacks;
    delete boss;
}

void MainLevel::spawnEntities(sf::RenderWindow& window){
        if (mode == CAMPAIGN && player->getScore() >= 1000){
                if (!bossSpawned){
                        clearVectors();
                        player->ammoIncrease(300);
                        player->armorIncrease(100);
                        player->healthIncrease(100);
                        bossSpawned=true;
                }
                        
        }
        else {
                mobileEnemies->spawnNewEntity(window, current);
                if (std::difftime(current, lastArmoredEnemy)>armoredInterval){
                        armoredEnemies.push_back(ArmoredEnemy());
                        lastArmoredEnemy=armoredEnemies.back().getSpawnTime();
                        armoredEnemies.back().setFired(lastArmoredEnemy);
                }
                if (std::difftime(current, lastCombinedEnemy)>assasinSpawnInterval){
                        combinedEnemies.push_back(CombinedEnemy());
                        lastCombinedEnemy=combinedEnemies.back().getSpawnTime();
                        combinedEnemies.back().setFired(lastCombinedEnemy);
                }
                ammoPacks->spawnNewEntity(window, current);
                armorPacks->spawnNewEntity(window, current);
                healthPacks->spawnNewEntity(window, current);
        }
        
}

void MainLevel::bulletPoll(sf::RenderWindow& window){
        if (!bullets.empty() && bullets.begin()->bulletLifeCycle())
                bullets.erase(bullets.begin());
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                bulletPosition=it->getPosition();
                it->bulletMove();
                it->entityDraw(window);
                collisionBullet(mobileEnemies->getMobileEnemies(), 15);
                collisionBullet(&armoredEnemies, 30);
                collisionBullet(&combinedEnemies, 60);
                collisionBulletBoss(1000);
        }
}

void MainLevel::collision(sf::RenderWindow& window){
        playerPosition=player->getPosition();
        mobileEnemies->collides(window, *player, current);
        collisionArmored(window);
        collisionAssasin(window);
        ammoPacks->collides(window, *player, current);
        armorPacks->collides(window, *player, current);
        healthPacks->collides(window, *player, current);
        collisionBoss(window);

}

void MainLevel::clearVectors(){
        bullets.clear();
        enemyBullets.clear();
        mobileEnemies->getMobileEnemies()->clear();
        armoredEnemies.clear();
        combinedEnemies.clear();
        ammoPacks->getAmmoPacks()->clear();
        armorPacks->getArmorPacks()->clear();
        healthPacks->getHealthPacks()->clear();
}


void MainLevel::setEasyDifficulty(){
        mobileEnemies->setSpawnInterval(2);
        int pickupSpawnInterval = 15;
        ammoPacks->setSpawnInterval(pickupSpawnInterval);
        armorPacks->setSpawnInterval(pickupSpawnInterval);
        healthPacks->setSpawnInterval(pickupSpawnInterval);
        armoredInterval = 5;
        enemyFireInterval = 1;
        assasinInterval[0] = 5;
        assasinInterval[1] = 0.5;
        assasinSpawnInterval = 30;
        shootingDamage = 3;
        enemyBulletDamage = 1;
        mode = SUFFERING_EASY;
}

void MainLevel::setMediumDifficulty(){
        mobileEnemies->setSpawnInterval(1);
        int pickupSpawnInterval = 25;
        ammoPacks->setSpawnInterval(pickupSpawnInterval);
        armorPacks->setSpawnInterval(pickupSpawnInterval);
        healthPacks->setSpawnInterval(pickupSpawnInterval);
        armoredInterval = 3;
        enemyFireInterval = 0.5;
        assasinInterval[0] = 4;
        assasinInterval[1] = 0.5;
        assasinSpawnInterval = 15;
        shootingDamage = 2;
        enemyBulletDamage = 2;
        mode = SUFFERING_MEDIUM;
}

void MainLevel::setHardDifficulty(){
        mobileEnemies->setSpawnInterval(0.5);
        int pickupSpawnInterval = 35;
        ammoPacks->setSpawnInterval(pickupSpawnInterval);
        armorPacks->setSpawnInterval(pickupSpawnInterval);
        healthPacks->setSpawnInterval(pickupSpawnInterval);
        armoredInterval = 1;
        enemyFireInterval = 0.1;
        assasinInterval[0] = 2;
        assasinInterval[1] = 0.5;
        assasinSpawnInterval = 5;
        shootingDamage = 1;
        enemyBulletDamage = 3;
        mode = SUFFERING_HARD;
}

void MainLevel::setCampaign(){
        setEasyDifficulty();
        mode = CAMPAIGN;
}

void MainLevel::collisionBoss(sf::RenderWindow& window){
        if (bossSpawned){
                boss->enemyMove(window, playerPosition);
                boss->entityDraw(window);
                if (std::difftime(current, assasinTransition[1])>assasinInterval[1]){
                        assasinTransition[1]=boss->setLowSpeed();
                }
                if (std::difftime(current, assasinTransition[0])>assasinInterval[0]){
                        assasinTransition[0]=boss->setHighSpeed();
                }
                enemyFiresABullet(boss, window);
                collidesBoss(window);
        }
}

void MainLevel::collisionBulletBoss(int increaseScore){
        if (bossSpawned){
                if (boss->collidesWithPlayer(bulletPosition)){
                        boss->healthDamage(shootingDamage);
                        if (boss->getHealth()<=0){
                                bossDefeated=true;
                                player->scoreIncrease(increaseScore);
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
        player->playerRender(window);
        player->playerMove(event, window);
        cursor->cursorUpdate(window);
        stats->statsRender(window, player->getHealth(), player->getArmor(), player->getAmmo(), player->getScore());
        keysCheck(window);
        return 7;
}

template <typename T>
void MainLevel::collisionBullet(T props, int increaseScore){
        for (auto it=props->begin(); it!=props->end(); ++it){
                if (it->collidesWithPlayer(bulletPosition)){
                        it->healthDamage(shootingDamage);
                        if (it->getHealth()<=0){
                                props->erase(it);
                                player->scoreIncrease(increaseScore);
                                break;
                        }
                }
        }
}

void MainLevel::collisionArmored(sf::RenderWindow& window){
        for (auto it=armoredEnemies.begin(); it!=armoredEnemies.end(); ++it){
                enemyFiresABullet(it, window);
                collides(it, window);  
        }
}

template <typename T>
void MainLevel::enemyFiresABullet(T it, sf::RenderWindow& window){
        if (std::difftime(current, it->getLastFired())>enemyFireInterval){
                it->setFired(current);
                enemyBullets.push_back(Bullet());
                enemyBullets.back().refresh();
                enemyBullets.back().bulletSetFloat(window, it->getPosition(), playerPosition);
        }
}

void MainLevel::collidesBoss(sf::RenderWindow& window){
    boss->enemyMove(window, playerPosition);
    boss->entityDraw(window);
    if (boss->collidesWithPlayer(playerPosition) && std::difftime(current, boss->getDamageTime())>0.05){
        boss->setDamageTime(std::time(&prevDamage));
        std::cout<<prevDamage;
        player->healthDamage(boss->getDamage());
    }
}

void MainLevel::enemyBulletPoll(sf::RenderWindow& window){
        playerPosition=player->getPosition();
        if (!enemyBullets.empty() && enemyBullets.begin()->bulletLifeCycle())
                enemyBullets.erase(enemyBullets.begin());
        for (auto it=enemyBullets.begin(); it!=enemyBullets.end(); ++it){
                it->bulletMove();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        player->healthDamage(enemyBulletDamage);
                }
        }
}

template <typename T>
void MainLevel::collides(T it, sf::RenderWindow& window){
    it->enemyMove(window, playerPosition);
    it->entityDraw(window);
    if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
        it->setDamageTime(std::time(&prevDamage));
        player->healthDamage(it->getDamage());
    }
}

void MainLevel::bulletFire(sf::Event& event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed && player->getAmmo() > 0 && (bullets.empty() || std::difftime(current, bullets.back().getSpawnTime())>0.005)) {
                bullets.push_back(Bullet());
                bullets.back().refresh();
                bullets.back().bulletSet(window, player->getPosition(), sf::Mouse::getPosition(window));
                player->ammoDecrement();
        }
}