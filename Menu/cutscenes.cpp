#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "cutscenes.hpp"
cutscenes::cutscenes() {
    if (!backgroundTexture[0].loadFromFile("Sprites/main_menu.png")) {
        std::cerr << "Missing file: Sprites/main_menu.png\n";
    }
    if (!backgroundTexture[1].loadFromFile("Sprites/menu1.png")) {
        std::cerr << "Missing file: Sprites/menu1.png\n";
    }
    if (!backgroundTexture[2].loadFromFile("Sprites/menu2.png")) {
        std::cerr << "Missing file: Sprites/menu2.png\n";
    }
    //backgroundShape=new button();
}

void cutscenes::cutDraw(sf::Event& event, sf::RenderWindow& window, int screen){
    //backgroundShape->cutsceneDraw(window, backgroundTexture[screen]);
    window.clear();
    backgroundShape.setTexture(backgroundTexture[1]);
    window.draw(backgroundShape);
    //while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
                window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            std::cout<<"mouse button pressed\n";
            //window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            std::cout<<"keyboard key pressed\n";
            //window.close();
        }
        if (event.type == sf::Event::KeyReleased) {
            std::cout<<"keyboard key released\n";
            //window.close();
        }
    //}
}
    //return screen;

cutscenes::~cutscenes(){
    //delete backgroundShape;
}
//void 