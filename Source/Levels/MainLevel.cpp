#include "MainLevel.hpp"

MainLevel::MainLevel(
        int difficulty,
        AbstractEntityContainer* ammoPacks, 
        AbstractEntityContainer* armorPacks, 
        AbstractEntityContainer* healthPacks, 
        AbstractEnemyContainer* mobileEnemies, 
        AbstractEnemyContainer* armoredEnemies,
        AbstractEnemyContainer* combinedEnemies,
        AbstractEnemyContainer* boss
) : AbstractLevel("Sprites/lvl1_bg.png") {
    this->mobileEnemies = mobileEnemies;
    this->armoredEnemies = armoredEnemies;
    this->combinedEnemies = combinedEnemies;
    this->boss = boss;
    this->ammoPacks = ammoPacks;
    this->armorPacks = armorPacks;
    this->healthPacks = healthPacks;
    mode = difficulty;
    switch (mode) {
        case SUFFERING_EASY:
                setEasyDifficulty();
                break;
        case SUFFERING_MEDIUM:
                setMediumDifficulty();
                break;
        case SUFFERING_HARD:
                setHardDifficulty();
                break;
        case CAMPAIGN:
                setCampaign();
                break;
        default:
                mode = CAMPAIGN;
                setCampaign();
                break;
    }
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
                        boss->spawnNewEntity(window);
                        player->ammoIncrease(300);
                        player->armorIncrease(100);
                        player->healthIncrease(100);
                        bossSpawned=true;
                }
                return;
                        
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
                if (bossSpawned) {
                        boss->checkCollisionWithPlayersBullet(bulletPosition, shootingDamage, 1000, *player);
                }
        }
}

void MainLevel::collision(sf::RenderWindow& window){
        playerPosition=player->getPosition();
        mobileEnemies->update(window, *player, enemyBullets);
        armoredEnemies->update(window, *player, enemyBullets);
        combinedEnemies->update(window, *player, enemyBullets);
        ammoPacks->update(window, *player);
        armorPacks->update(window, *player);
        healthPacks->update(window, *player);
        if (bossSpawned) {
                if (!boss->getContainerLength()) {
                        bossDefeated = true;
                        return;
                }
                boss->update(window, *player, enemyBullets);
        }

}

void MainLevel::clearVectors(){
        bullets.clear();
        enemyBullets.clear();
        mobileEnemies->clear();
        armoredEnemies->clear();
        combinedEnemies->clear();
        ammoPacks->clear();
        armorPacks->clear();
        healthPacks->clear();
}


void MainLevel::setEasyDifficulty(){
        mobileEnemies->setSpawnInterval(2);
        int pickupSpawnInterval = 15;
        ammoPacks->setSpawnInterval(pickupSpawnInterval);
        armorPacks->setSpawnInterval(pickupSpawnInterval);
        healthPacks->setSpawnInterval(pickupSpawnInterval);
        armoredEnemies->setSpawnInterval(5);
        combinedEnemies->setSpawnInterval(30);
        shootingDamage = 3;
}

void MainLevel::setMediumDifficulty(){
        mobileEnemies->setSpawnInterval(1);
        int pickupSpawnInterval = 25;
        ammoPacks->setSpawnInterval(pickupSpawnInterval);
        armorPacks->setSpawnInterval(pickupSpawnInterval);
        healthPacks->setSpawnInterval(pickupSpawnInterval);
        armoredEnemies->setSpawnInterval(3);
        combinedEnemies->setSpawnInterval(15);
        shootingDamage = 2;
        enemyBulletDamage = 2;
}

void MainLevel::setHardDifficulty(){
        mobileEnemies->setSpawnInterval(0.5);
        int pickupSpawnInterval = 35;
        ammoPacks->setSpawnInterval(pickupSpawnInterval);
        armorPacks->setSpawnInterval(pickupSpawnInterval);
        healthPacks->setSpawnInterval(pickupSpawnInterval);
        armoredEnemies->setSpawnInterval(1);
        combinedEnemies->setSpawnInterval(5);
        shootingDamage = 2;
        enemyBulletDamage = 2;
}

void MainLevel::setCampaign(){
        setEasyDifficulty();
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