#include "player.hpp"

player::player():aliveEntity(){
    
}

void player::playerMove(sf::Event& event, sf::RenderWindow& window){
    window.pollEvent(event);
    if (event.type == sf::Event::KeyPressed)
            {
                std::cout<<"GAY";
            }
}