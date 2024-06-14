#include "armorPackContainer.hpp"

armorPackContainer::armorPackContainer(){

}

std::time_t armorPackContainer::pushPack(){
    armorPacks.push_back(armorPack());
    armorPacks.back().refresh();
    return armorPacks.back().getTime();
}

void armorPackContainer::clearVector(){
    armorPacks.clear();
}

void armorPackContainer::collisionArmor(sf::RenderWindow& window, player* myPlayer, sf::Vector2f playerPosition){
        for (auto it=armorPacks.begin(); it!=armorPacks.end(); ++it){
                it->refresh();
                it->entityDraw(window);
                if (it->collidesWithPlayer(playerPosition)){
                        myPlayer->armorIncrease(it->getArmor());
                        armorPacks.erase(it);
                        myPlayer->scoreIncrease(5);
                        break;
                }
        }
}