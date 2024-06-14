#include "mobileContainer.hpp"

mobileContainer::mobileContainer(){

}

void mobileContainer::collisionMobile(sf::RenderWindow& window, std::time_t current, player* myPlayer, std::time_t* prevDamage){
        playerPosition=myPlayer->getPosition();
        for (auto it=mobileEnemies.begin(); it!=mobileEnemies.end(); ++it){
            it->enemyMove(window, playerPosition);
            it->entityDraw(window);
            if (it->collidesWithPlayer(playerPosition) && std::difftime(current, it->getDamageTime())>0.05){
                it->setDamageTime(std::time(prevDamage));
                myPlayer->healthDamage(it->getDamage());
        }  
        }
}

void mobileContainer::clearVector(){
    mobileEnemies.clear();
}

std::time_t mobileContainer::pushEnemy(){
    mobileEnemies.push_back(enemyMobile());
    return mobileEnemies.back().getTime();
}

void mobileContainer::collisionBullet(int increaseScore, sf::Vector2f bulletPosition, int shootingDamage, player* myPlayer){
    for (auto it=mobileEnemies.begin(); it!=mobileEnemies.end(); ++it){
                if (it->collidesWithPlayer(bulletPosition)){
                        it->healthDamage(shootingDamage);
                        if (it->getHealth()<=0){
                                mobileEnemies.erase(it);
                                myPlayer->scoreIncrease(increaseScore);
                                break;
                        }
                }
        }
}
