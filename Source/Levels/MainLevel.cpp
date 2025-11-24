#include "MainLevel.hpp"

MainLevel::MainLevel(
        std::string background,
        std::vector<AbstractEntityContainer*>& entitiesContainers,
        std::vector<AbstractEnemyContainer*>& enemyContainers,
        int bossReachScore,
        std::string bossBackground,
        int nextLevelCode,
        AbstractEnemyContainer* boss
) : AbstractLevel(background) {
    this->boss = boss;
    this->mode = CAMPAIGN;
    this->bossReachScore = bossReachScore;
    this->bossBackground = bossBackground;
    this->nextLevelCode = nextLevelCode;
    bossSpawned = false;
    this->entityContainers = entitiesContainers;
    this->enemyContainers = enemyContainers;
}

MainLevel::MainLevel(
        std::string background,
        std::vector<AbstractEntityContainer*>& entitiesContainers,
        std::vector<AbstractEnemyContainer*>& enemyContainers
) : AbstractLevel(background) {
    this->boss = nullptr;
    this->mode = ETERNAL;
    this->bossReachScore = 0;
    this->bossBackground = "";
    this->nextLevelCode = 0;
    bossSpawned = false;
    this->entityContainers = entitiesContainers;
    this->enemyContainers = enemyContainers;
}

MainLevel::~MainLevel(){
    clearEntities();
    for (auto it = entityContainers.begin(); it != entityContainers.end(); ++it) {
        delete (*it);
    }
    for (auto it = enemyContainers.begin(); it != enemyContainers.end(); ++it) {
        delete (*it);
    }
    delete boss;
}

void MainLevel::spawnEntities(sf::RenderWindow& window){
        if (mode == CAMPAIGN && player->getScore() >= bossReachScore){
                if (!bossSpawned){
                        clearEntities();
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

        for (auto it = entityContainers.begin(); it != entityContainers.end(); ++it) {
                (*it)->spawnNewEntity(window);
        }

        for (auto it = enemyContainers.begin(); it != enemyContainers.end(); ++it) {
                (*it)->spawnNewEntity(window);
        }
}

void MainLevel::bulletPoll(sf::RenderWindow& window){
        if (!bullets.empty() && bullets.begin()->bulletLifeCycleExpired())
                bullets.erase(bullets.begin());
        for (auto it=bullets.begin(); it!=bullets.end(); ++it){
                sf::Vector2f bulletPosition=it->getPosition();
                it->bulletMove();
                it->entityDraw(window);
                for (auto enemyIt = enemyContainers.begin(); enemyIt != enemyContainers.end(); ++enemyIt) {
                        (*enemyIt)->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                }
                if (bossSpawned) {
                        boss->checkCollisionWithPlayersBullet(bulletPosition, it->getDamage(), *player);
                }
        }
}

void MainLevel::update(sf::RenderWindow& window){
        sf::Vector2f playerPosition = player->getPosition();
        for (auto it = entityContainers.begin(); it != entityContainers.end(); ++it) {
                (*it)->update(window, *player);
        }

        for (auto it = enemyContainers.begin(); it != enemyContainers.end(); ++it) {
                (*it)->update(window, *player, enemyBullets);
        }

        if (bossSpawned) {
                if (!boss->getContainerLength()) {
                        endGame = true;
                        return;
                }
                boss->update(window, *player, enemyBullets);
        }

}

void MainLevel::clearEntities(){
        bullets.clear();
        enemyBullets.clear();
        for (auto it = entityContainers.begin(); it != entityContainers.end(); ++it) {
                (*it)->clear();
        }

        for (auto it = enemyContainers.begin(); it != enemyContainers.end(); ++it) {
                (*it)->clear();
        }
}

int MainLevel::render(sf::Event& event, sf::RenderWindow& window){
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