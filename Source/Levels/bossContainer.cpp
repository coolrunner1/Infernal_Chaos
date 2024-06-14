#include "bossContainer.hpp"

bossContainer::bossContainer(){

}

void bossContainer::collisionBoss(sf::RenderWindow& window, bool bossSpawned, std::time_t* assasinTransitionFirst, std::time_t* assasinTransitionSecond, float assasinInterval[2], std::time_t current, sf::Vector2f playerPosition, std::vector<bullet>* enemyBullets, player* myPlayer, std::time_t* prevDamage, int enemyFireInterval){
        if (bossSpawned){
                this->current=current;
                this->playerPosition=playerPosition;
                this->enemyFireInterval=enemyFireInterval;
                bossFinal.enemyMove(window, playerPosition);
                bossFinal.entityDraw(window);
                if (std::difftime(current, *assasinTransitionSecond)>assasinInterval[1]){
                        *assasinTransitionSecond=bossFinal.setLowSpeed();
                }
                if (std::difftime(current, *assasinTransitionFirst)>assasinInterval[0]){
                        *assasinTransitionFirst=bossFinal.setHighSpeed();
                }
                bossFiresABullet(window, enemyBullets);
                collidesBoss(window, myPlayer, prevDamage);
        }
}

bool bossContainer::collisionBulletBoss(int increaseScore, bool bossSpawned, sf::Vector2f bulletPosition, int shootingDamage, player* myPlayer){
        if (bossSpawned){
                if (bossFinal.collidesWithPlayer(bulletPosition)){
                        bossFinal.healthDamage(shootingDamage);
                        if (bossFinal.getHealth()<=0){
                                myPlayer->scoreIncrease(increaseScore);
                                return true;
                        }
                }
        }
        return false;
        
}

void bossContainer::collidesBoss(sf::RenderWindow& window, player* myPlayer, std::time_t* prevDamage){
    bossFinal.enemyMove(window, playerPosition);
    bossFinal.entityDraw(window);
    if (bossFinal.collidesWithPlayer(playerPosition) && std::difftime(current, bossFinal.getDamageTime())>0.05){
        bossFinal.setDamageTime(std::time(prevDamage));
        myPlayer->healthDamage(bossFinal.getDamage());
    }
}

void bossContainer::bossFiresABullet(sf::RenderWindow& window, std::vector<bullet>* enemyBullets){
        if (std::difftime(current, bossFinal.getLastFired())>enemyFireInterval){
                        bossFinal.setFired(current);
                        enemyBullets->push_back(bullet());
                        enemyBullets->back().refresh();
                        enemyBullets->back().bulletSetFloat(window, bossFinal.getPosition(), playerPosition);
                }
}