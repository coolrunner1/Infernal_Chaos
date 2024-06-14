#include "healthPackContainer.hpp"

healthPackContainer::healthPackContainer(){

}

std::time_t healthPackContainer::pushPack(){
    healthPacks.push_back(healthPack());
    healthPacks.back().refresh();
    return healthPacks.back().getTime();
}

void healthPackContainer::clearVector(){
    healthPacks.clear();
}

void healthPackContainer::collisionHealth(sf::RenderWindow& window, player* myPlayer, sf::Vector2f playerPosition){
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