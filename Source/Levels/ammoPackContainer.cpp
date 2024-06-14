#include "ammoPackContainer.hpp"

ammoPackContainer::ammoPackContainer(){

}

std::time_t ammoPackContainer::pushPack(){
    ammoPacks.push_back(ammoPack());
    ammoPacks.back().refresh();
    return ammoPacks.back().getTime();
}

void ammoPackContainer::clearVector(){
    ammoPacks.clear();
}

void ammoPackContainer::collisionAmmo(sf::RenderWindow& window, player* myPlayer, sf::Vector2f playerPosition){
        for (auto it=ammoPacks.begin(); it!=ammoPacks.end(); ++it){
                it->refresh();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->ammoIncrease(it->getAmmo());
                        ammoPacks.erase(it);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
}