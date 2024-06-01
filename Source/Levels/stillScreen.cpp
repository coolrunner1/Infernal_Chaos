#include "stillScreen.hpp"

stillScreen::stillScreen(){
    if (!gameoverTexture.loadFromFile("Sprites/game_over.png")) {
            std::cerr << "Missing file: Sprites/game_over.png"<<std::endl;
    }
    gameoverShape.setTexture(gameoverTexture);
    gameoverShape.setScale(6, 6);
    gameoverShape.setPosition(250,250);
    if (!pauseTexture.loadFromFile("Sprites/pause.png")) {
            std::cerr << "Missing file: Sprites/pause.png"<<std::endl;
    }
    pauseShape.setTexture(pauseTexture);
    pauseShape.setScale(6, 6);
    pauseShape.setPosition(400,250);
    if (!winTexture.loadFromFile("Sprites/win.png")) {
            std::cerr << "Missing file: Sprites/win.png"<<std::endl;
    }
    winShape.setTexture(winTexture);
    winShape.setScale(6, 6);
    winShape.setPosition(350,250);
}

void stillScreen::pause(sf::RenderWindow& window){
    window.draw(pauseShape);
    window.display();
}

void stillScreen::gameOver(sf::RenderWindow& window){
    window.draw(gameoverShape);
    window.display();
}

void stillScreen::youWin(sf::RenderWindow& window){
    window.draw(winShape);
    window.display();
}