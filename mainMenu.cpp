#include "mainMenu.hpp"

main_menu::main_menu() {
    if (!backgroundTexture.loadFromFile("Sprites/main_menu.png")) {
        std::cerr << "Missing file: Sprites/main_menu.png\n";
    }
    pathPlay="Sprites/Play.png";
    pathQuit="Sprites/quit.png";
    backgroundShape.setTexture(backgroundTexture);
    pathInfCamp="Sprites/infernal_campaign.png";
}

void main_menu::mainMenuDraw(sf::RenderWindow& window){
    window.clear();
    window.draw(backgroundShape);
    buttons[0].buttonDraw(350, 50, 10, 10, pathPlay, window);
    buttons[1].buttonDraw(350, 500, 10, 10, pathQuit, window);
}

void main_menu::secondMenuDraw(sf::RenderWindow& window){
    window.clear();
    window.draw(backgroundShape);
    //std::string pathQuit="Sprites/quit.png";
    buttons[2].buttonDraw(350, 50, 10, 10, pathInfCamp, window);
    //buttons[3].buttonDraw(350, 500, 10, 10, pathQuit, window);
}

int main_menu::mainButtons(sf::Event& event, sf::RenderWindow& window){
    mainMenuDraw(window);
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
                window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
                if (buttons[0].isClicked(window)) {
                    std::cout << "Start button clicked!\n";
                    secondMenuDraw(window);
                    std::cin>>pathPlay;
                }
                if (buttons[1].isClicked(window)) {
                    window.close();
                }
        }
    }
    return 0;
}