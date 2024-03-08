#include "mainMenu.hpp"

main_menu::main_menu() {
    if (!backgroundTexture.loadFromFile("Sprites/main_menu.png")) {
        std::cerr << "Missing file: Sprites/main_menu.png\n";
    }
    backgroundShape.setTexture(backgroundTexture);
}

void main_menu::mainMenuDraw(sf::RenderWindow& window){
    backgroundShape.setTexture(backgroundTexture);
    //window.clear();
    window.draw(backgroundShape);
    //internWindow.display();
}