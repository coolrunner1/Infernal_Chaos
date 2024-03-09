#include "mainMenu.hpp"

main_menu::main_menu() {
    if (!backgroundTexture.loadFromFile("Sprites/main_menu.png")) {
        std::cerr << "Missing file: Sprites/main_menu.png\n";
    }
    path[0]="Sprites/Play.png";
    path[1]="Sprites/quit.png";
    path[2]="Sprites/infernal_campaign.png";
    backgroundShape.setTexture(backgroundTexture);
    //buttons[0]={button(path[0])};
    for (int i=0; i<numOfButtons; i++)
        buttons[i] = new button {button(path[i])};
}

main_menu::~main_menu(){
    for (int i=0; i<numOfButtons; i++)
        delete buttons[i];
}

void main_menu::mainMenuDraw(sf::RenderWindow& window){
    window.clear();
    window.draw(backgroundShape);
    buttons[0]->buttonDraw(350, 50, 10, 10, window);
    buttons[1]->buttonDraw(350, 500, 10, 10, window);
    //window.display();
}

void main_menu::secondMenuDraw(sf::RenderWindow& window){
    window.clear();
    //window.draw(backgroundShape);
    //std::string pathQuit="Sprites/quit.png";
    buttons[2]->buttonDraw(350, 50, 10, 10, window);
    //buttons[3].buttonDraw(350, 500, 10, 10, pathQuit, window);
    //window.display();
    std::cerr<<"entered\n";
}

int main_menu::mainButtons(sf::Event& event, sf::RenderWindow& window){
    std::cout<<"ENTERED MAINBUTT\n";
    mainMenuDraw(window);
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
                window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
                if (buttons[0]->isClicked(window)) {
                    std::cout << "Start button clicked!\n";
                    /*secondMenuDraw(window);
                    window.display();*/
                    return 1;
                    secButtons(event, window);
                    std::cout<<path[0]<<std::endl;
                }
                if (buttons[1]->isClicked(window)) {
                    window.close();
                }
        }
    }
    return 0;
}

int main_menu::secButtons(sf::Event& event, sf::RenderWindow& window){
    std::cout<<"ENTERED SECBUTT\n";
    secondMenuDraw(window);
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
                window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
                if (buttons[3]->isClicked(window)) {
                    std::cout << "GAY!\n";
                    
                    window.display(); 
                    std::cout<<path[0]<<std::endl;
                }
                /*if (buttons[1]->isClicked(window)) {
                    window.close();
                }*/
        }
    }
    return 0;
}
/*int main_menu::mainButtons(sf::Event& event, sf::RenderWindow& window){
    mainMenuDraw(window);

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (buttons[0].isClicked(window)) {
                    std::cout << "Start button clicked!\n";
                    secondMenuDraw(window);
                    window.display();
                }
                if (buttons[1].isClicked(window)) {
                    window.close();
                }
            }
        }
    }

    return 0;
}*/