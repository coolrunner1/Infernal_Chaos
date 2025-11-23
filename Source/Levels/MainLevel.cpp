#include "MainLevel.hpp"

MainLevel::MainLevel(
        AbstractEntityContainer* ammoPacks, 
        AbstractEntityContainer* armorPacks, 
        AbstractEntityContainer* healthPacks, 
        AbstractEnemyContainer* mobileEnemies, 
        AbstractEnemyContainer* armoredEnemies,
        AbstractEnemyContainer* combinedEnemies
) : AbstractLevel("Sprites/lvl1_bg.png"){
    boss = new Boss();
    assasinTransition[0]=assasinTransition[1]=lastCombinedEnemy=start;
    this->mobileEnemies = mobileEnemies;
    this->armoredEnemies = armoredEnemies;
    this->combinedEnemies = combinedEnemies;
    this->ammoPacks = ammoPacks;
    this->armorPacks = armorPacks;
    this->healthPacks = healthPacks;
}

MainLevel::~MainLevel(){
    clearVectors();
    delete mobileEnemies;
    delete armoredEnemies;
    delete combinedEnemies;
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
        mobileEnemies->spawnNewEntity(window);
        armoredEnemies->spawnNewEntity(window);
        combinedEnemies->spawnNewEntity(window);
        ammoPacks->spawnNewEntity(window);
        armorPacks->spawnNewEntity(window);
        healthPacks->spawnNewEntity(window);
}

void MainLevel::bulletPoll(sf::RenderWindow& window){
        if (!bullets.empty() && bullets.begin()->bulletLifeCycleExpired())
                bullets.erase(bullets.begin());
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                bulletPosition=it->getPosition();
                it->bulletMove();
                it->entityDraw(window);
                mobileEnemies->checkCollisionWithPlayersBullet(bulletPosition, shootingDamage, 15, *player);
                armoredEnemies->checkCollisionWithPlayersBullet(bulletPosition, shootingDamage, 30, *player);
                combinedEnemies->checkCollisionWithPlayersBullet(bulletPosition, shootingDamage, 60, *player);
                collisionBulletBoss(1000);
        }
}

void MainLevel::collision(sf::RenderWindow& window){
        playerPosition=player->getPosition();
        mobileEnemies->collides(window, *player);
        armoredEnemies->collides(window, *player, enemyBullets);
        combinedEnemies->collides(window, *player, enemyBullets);
        ammoPacks->collides(window, *player);
        armorPacks->collides(window, *player);
        healthPacks->collides(window, *player);
        collisionBoss(window);

}

void MainLevel::clearVectors(){
        bullets.clear();
        enemyBullets.clear();
}


void MainLevel::setEasyDifficulty(){
        mobileEnemies->setSpawnInterval(2);
        int pickupSpawnInterval = 15;
        ammoPacks->setSpawnInterval(pickupSpawnInterval);
        armorPacks->setSpawnInterval(pickupSpawnInterval);
        healthPacks->setSpawnInterval(pickupSpawnInterval);
        armoredEnemies->setSpawnInterval(5);
        combinedEnemies->setSpawnInterval(30);
        enemyFireInterval = 1;
        assasinInterval[0] = 5;
        assasinInterval[1] = 0.5;
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
        armoredEnemies->setSpawnInterval(3);
        combinedEnemies->setSpawnInterval(15);
        enemyFireInterval = 0.5;
        assasinInterval[0] = 4;
        assasinInterval[1] = 0.5;
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
        armoredEnemies->setSpawnInterval(1);
        combinedEnemies->setSpawnInterval(5);
        enemyFireInterval = 0.1;
        assasinInterval[0] = 2;
        assasinInterval[1] = 0.5;
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
                        boss->setLowSpeed();
                        boss->updateTransitionToSlowTimestamp();
                }
                if (std::difftime(current, assasinTransition[0])>assasinInterval[0]){
                        boss->setHighSpeed();
                        boss->updateTransitionToFastTimestamp();
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

int MainLevel::levelRender(sf::Event& event, sf::RenderWindow& window){
        std::time(&current);
        setBackground(window);
        window.setMouseCursorVisible(false);
        player->fireABullet(event, window, bullets);
        spawnEntities(window);
        bulletPoll(window);
        enemyBulletPoll(window);
        collision(window);
        player->playerRender(window);
        player->playerMove(event, window);
        cursor->cursorUpdate(window);
        stats->statsRender(
                window, 
                player->getHealth(), 
                player->getArmor(), 
                player->getAmmo(), 
                player->getScore()
        );
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
        if (!enemyBullets.empty() && enemyBullets.begin()->bulletLifeCycleExpired())
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