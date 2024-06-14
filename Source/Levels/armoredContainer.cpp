#include "armoredContainer.hpp"

armoredContainer::armoredContainer(){
    
}

std::time_t armoredContainer::pushEnemy(){
    armoredEnemies.push_back(armoredEnemy());
    lastEnemy=armoredEnemies.back().getTime();
    armoredEnemies.back().setFired(lastEnemy);
    return lastEnemy;
}

void armoredContainer::clearVector(){
    armoredEnemies.clear();
}

void armoredContainer::collisionBullet(int increaseScore, sf::Vector2f bulletPosition, int shootingDamage, player* myPlayer){
    for (auto it=armoredEnemies.begin(); it!=armoredEnemies.end(); ++it){
                if (it->collidesWithPlayer(bulletPosition)){
                        it->healthDamage(shootingDamage);
                        if (it->getHealth()<=0){
                                armoredEnemies.erase(it);
                                myPlayer->scoreIncrease(increaseScore);
                                break;
                        }
                }
        }
}

void armoredContainer::collisionArmored(sf::RenderWindow& window, std::time_t current, sf::Vector2f playerPosition, std::vector<bullet>* enemyBullets, player* myPlayer, std::time_t* prevDamage, int enemyFireInterval){
        for (auto it=armoredEnemies.begin(); it!=armoredEnemies.end(); ++it){
                if (std::difftime(current, it->getLastFired())>enemyFireInterval){
                        it->setFired(current);
                        enemyBullets->push_back(bullet());
                        enemyBullets->back().refresh();
                        enemyBullets->back().bulletSetFloat(window, it->getPosition(), playerPosition);
                }
                it->enemyMove(window, playerPosition);
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
                    it->setDamageTime(std::time(prevDamage));
                    myPlayer->healthDamage(it->getDamage());
                }  
        }
}