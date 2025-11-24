#include "MainLevel.hpp"

MainLevel::MainLevel(
        int mode,
        std::string background,
        AbstractEntityContainer* ammoPacks, 
        AbstractEntityContainer* armorPacks, 
        AbstractEntityContainer* healthPacks, 
        AbstractEnemyContainer* mobileEnemies, 
        AbstractEnemyContainer* armoredEnemies,
        AbstractEnemyContainer* combinedEnemies,
        AbstractEnemyContainer* boss
) : AbstractLevel(background) {
    this->mobileEnemies = mobileEnemies;
    this->armoredEnemies = armoredEnemies;
    this->combinedEnemies = combinedEnemies;
    this->boss = boss;
    this->ammoPacks = ammoPacks;
    this->armorPacks = armorPacks;
    this->healthPacks = healthPacks;
    this->mode = mode;
    bossSpawned = false;
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
                        setBackground("Sprites/lvl3_bg.png");
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
                sf::Vector2f bulletPosition=it->getPosition();
                it->bulletMove();
                it->entityDraw(window);
                mobileEnemies->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), 15, *player);
                armoredEnemies->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), 30, *player);
                combinedEnemies->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), 60, *player);
                if (bossSpawned) {
                        boss->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), 1000, *player);
                }
        }
}

void MainLevel::update(sf::RenderWindow& window){
        sf::Vector2f playerPosition = player->getPosition();
        mobileEnemies->update(window, *player, enemyBullets);
        armoredEnemies->update(window, *player, enemyBullets);
        combinedEnemies->update(window, *player, enemyBullets);
        ammoPacks->update(window, *player);
        armorPacks->update(window, *player);
        healthPacks->update(window, *player);
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
        mobileEnemies->clear();
        armoredEnemies->clear();
        combinedEnemies->clear();
        ammoPacks->clear();
        armorPacks->clear();
        healthPacks->clear();
}

int MainLevel::levelRender(sf::Event& event, sf::RenderWindow& window){
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
        return 7;
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