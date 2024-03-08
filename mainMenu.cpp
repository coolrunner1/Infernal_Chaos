#include "mainMenu.hpp"
#include <SFML/Graphics.hpp>
int main_menu::mainMenuDraw(sf::RenderWindow& window){
    std::cerr<<"GAY\n";
    if (!backgroundTexture.loadFromFile("Sprites/main_menu.png")){
        std::clog<<"Missing file: Sprites/main_menu.png\n";
        return EXIT_FAILURE;
    }
    backgroundSprite.setTexture(backgroundTexture);
    //window.clear();
    //window.draw(backgroundSprite);
    //internWindow.display();
}

main_menu::main_menu(sf::RenderWindow& window) {
    std::cerr<<"GAY\n";
    if (!backgroundTexture.loadFromFile("Sprites/main_menu.png")){
        std::clog<<"Missing file: Sprites/main_menu.png\n";
        //return EXIT_FAILURE;
    }
}