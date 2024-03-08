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
    std::string pathPlay="Sprites/Play.png";
    std::string pathQuit="Sprites/quit.png";
    buttons[0].buttonDraw(350, 50, 10, 10, pathPlay, window);
    buttons[1].buttonDraw(350, 500, 10, 10, pathQuit, window);
    //internWindow.display();
}