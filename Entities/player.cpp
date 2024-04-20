#include "player.hpp"

player::player():aliveEntity(){
    
}

void player::playerMove(sf::Event& event, sf::RenderWindow& window){

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                std::cout<<"GAY\n";
                //window.close();
            }
}