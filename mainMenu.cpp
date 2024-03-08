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

int main_menu::mainButtons(sf::Event& event, sf::RenderWindow& window){
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
                window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
                if (buttons[0].isClicked(window)) {
                    std::cout << "Start button clicked!\n";
                    //second screen
                }
                if (buttons[1].isClicked(window)) {
                    window.close();
                }
        }
    }
    return 0;
}