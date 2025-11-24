#include "MainLevel.hpp"

MainLevel::MainLevel(
        std::string background,
        int bossReachScore,
        std::string bossBackground,
        int nextLevelCode,
        AbstractEntityContainer* entitySlot1, 
        AbstractEntityContainer* entitySlot2, 
        AbstractEntityContainer* entitySlot3, 
        AbstractEntityContainer* entitySlot4, 
        AbstractEntityContainer* entitySlot5, 
        AbstractEntityContainer* entitySlot6,  
        AbstractEnemyContainer* enemySlot1, 
        AbstractEnemyContainer* enemySlot2, 
        AbstractEnemyContainer* enemySlot3, 
        AbstractEnemyContainer* enemySlot4, 
        AbstractEnemyContainer* enemySlot5, 
        AbstractEnemyContainer* enemySlot6, 
        AbstractEnemyContainer* boss
) : AbstractLevel(background) {
    this->enemySlot1 = enemySlot1;
    this->enemySlot2 = enemySlot2;
    this->enemySlot3 = enemySlot3;
    this->enemySlot4 = enemySlot4;
    this->enemySlot5 = enemySlot5;
    this->enemySlot6 = enemySlot6;
    this->boss = boss;
    this->entitySlot1 = entitySlot1;
    this->entitySlot2 = entitySlot2;
    this->entitySlot3 = entitySlot3;
    this->entitySlot4 = entitySlot4;
    this->entitySlot5 = entitySlot5;
    this->entitySlot6 = entitySlot6;
    this->mode = CAMPAIGN;
    this->bossReachScore = bossReachScore;
    this->bossBackground = bossBackground;
    this->nextLevelCode = nextLevelCode;
    bossSpawned = false;
}

MainLevel::MainLevel(
        std::string background,
        AbstractEntityContainer* entitySlot1, 
        AbstractEntityContainer* entitySlot2, 
        AbstractEntityContainer* entitySlot3, 
        AbstractEntityContainer* entitySlot4, 
        AbstractEntityContainer* entitySlot5, 
        AbstractEntityContainer* entitySlot6,  
        AbstractEnemyContainer* enemySlot1, 
        AbstractEnemyContainer* enemySlot2, 
        AbstractEnemyContainer* enemySlot3, 
        AbstractEnemyContainer* enemySlot4, 
        AbstractEnemyContainer* enemySlot5, 
        AbstractEnemyContainer* enemySlot6
) : AbstractLevel(background) {
    this->enemySlot1 = enemySlot1;
    this->enemySlot2 = enemySlot2;
    this->enemySlot3 = enemySlot3;
    this->enemySlot4 = enemySlot4;
    this->enemySlot5 = enemySlot5;
    this->enemySlot6 = enemySlot6;
    this->boss = nullptr;
    this->entitySlot1 = entitySlot1;
    this->entitySlot2 = entitySlot2;
    this->entitySlot3 = entitySlot3;
    this->entitySlot4 = entitySlot4;
    this->entitySlot5 = entitySlot5;
    this->entitySlot6 = entitySlot6;
    this->mode = ETERNAL;
    this->bossReachScore = 0;
    this->bossBackground = "";
    this->nextLevelCode = 0;
    bossSpawned = false;
}

MainLevel::~MainLevel(){
    clearVectors();
    delete enemySlot1;
    delete enemySlot2;
    delete enemySlot3;
    delete entitySlot1;
    delete entitySlot2;
    delete entitySlot3;
    delete boss;
}

void MainLevel::spawnEntities(sf::RenderWindow& window){
        if (mode == CAMPAIGN && player->getScore() >= bossReachScore){
                if (!bossSpawned){
                        clearVectors();
                        boss->spawnNewEntity(window);
                        player->ammoIncrease(300);
                        player->armorIncrease(100);
                        player->healthIncrease(100);
                        if (bossBackground.length()) {
                                setBackground(bossBackground);
                        }
                        bossSpawned = true;
                }
                return;
                        
        }
        enemySlot1->spawnNewEntity(window);
        enemySlot2->spawnNewEntity(window);
        enemySlot3->spawnNewEntity(window);
        enemySlot4->spawnNewEntity(window);
        enemySlot5->spawnNewEntity(window);
        enemySlot6->spawnNewEntity(window);
        entitySlot1->spawnNewEntity(window);
        entitySlot2->spawnNewEntity(window);
        entitySlot3->spawnNewEntity(window);
        entitySlot4->spawnNewEntity(window);
        entitySlot5->spawnNewEntity(window);
        entitySlot6->spawnNewEntity(window);
}

void MainLevel::bulletPoll(sf::RenderWindow& window){
        if (!bullets.empty() && bullets.begin()->bulletLifeCycleExpired())
                bullets.erase(bullets.begin());
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                sf::Vector2f bulletPosition=it->getPosition();
                it->bulletMove();
                it->entityDraw(window);
                enemySlot1->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                enemySlot2->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                enemySlot3->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                enemySlot4->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                enemySlot5->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                enemySlot6->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                if (bossSpawned) {
                        boss->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                }
        }
}

void MainLevel::update(sf::RenderWindow& window){
        sf::Vector2f playerPosition = player->getPosition();
        enemySlot1->update(window, *player, enemyBullets);
        enemySlot2->update(window, *player, enemyBullets);
        enemySlot3->update(window, *player, enemyBullets);
        enemySlot4->update(window, *player, enemyBullets);
        enemySlot5->update(window, *player, enemyBullets);
        enemySlot6->update(window, *player, enemyBullets);
        entitySlot1->update(window, *player);
        entitySlot2->update(window, *player);
        entitySlot3->update(window, *player);
        entitySlot4->update(window, *player);
        entitySlot5->update(window, *player);
        entitySlot6->update(window, *player);
        if (bossSpawned) {
                if (!boss->getContainerLength()) {
                        endGame = true;
                        return;
                }
                boss->update(window, *player, enemyBullets);
        }

}

void MainLevel::clearVectors(){
        bullets.clear();
        enemyBullets.clear();
        enemySlot1->clear();
        enemySlot2->clear();
        enemySlot3->clear();
        enemySlot4->clear();
        enemySlot5->clear();
        enemySlot6->clear();
        entitySlot1->clear();
        entitySlot2->clear();
        entitySlot3->clear();
        entitySlot4->clear();
        entitySlot5->clear();
        entitySlot6->clear();
}

int MainLevel::levelRender(sf::Event& event, sf::RenderWindow& window){
        if (endGame && nextLevelCode) {
                return nextLevelCode;
        }
        refreshBackground(window);
        window.setMouseCursorVisible(false);
        player->fireABullet(event, window, bullets);
        spawnEntities(window);
        bulletPoll(window);
        enemyBulletPoll(window);
        update(window);
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
        return CONTINUE_LEVEL_EXECUTION;
}

void MainLevel::enemyBulletPoll(sf::RenderWindow& window){
        sf::Vector2f playerPosition=player->getPosition();
        if (!enemyBullets.empty() && enemyBullets.begin()->bulletLifeCycleExpired())
                enemyBullets.erase(enemyBullets.begin());
        for (auto it=enemyBullets.begin(); it!=enemyBullets.end(); ++it){
                it->bulletMove();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        player->healthDamage(it->getDamage());
                }
        }
}