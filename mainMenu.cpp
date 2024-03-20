#include "mainMenu.hpp"

main_menu::main_menu() {
    if (!backgroundTexture[0].loadFromFile("Sprites/main_menu.png")) {
        std::cerr << "Missing file: Sprites/main_menu.png\n";
    }
    if (!backgroundTexture[1].loadFromFile("Sprites/menu1.png")) {
        std::cerr << "Missing file: Sprites/menu1.png\n";
    }
    if (!backgroundTexture[2].loadFromFile("Sprites/menu2.png")) {
        std::cerr << "Missing file: Sprites/menu2.png\n";
    }
    path[0]="Sprites/infernal_chaos_title.png";
    path[1]="Sprites/Play.png";
    path[2]="Sprites/quit.png";
    path[3]="Sprites/infernal_campaign.png";
    path[4]="Sprites/perpetual_suffering.png";
    path[5]="Sprites/back.png";
    //buttons[0]={button(path[0])};
    for (int i=0; i<numOfButtons; i++)
        buttons[i] = new button {button(path[i])};
}

main_menu::~main_menu(){
    for (int i=0; i<numOfButtons; i++)
        delete buttons[i];
}

void main_menu::menuButtons(sf::RenderWindow& window){
    buttons[0]->buttonDraw(350, 50, 10, 10, window);
	buttons[1]->buttonDraw(350, 250, 10, 10, window);
    buttons[2]->buttonDraw(350, 500, 10, 10, window);
}

void main_menu::secondScrButtons(sf::RenderWindow& window){
    buttons[3]->buttonDraw(350, 50, 3, 3, window);
    buttons[4]->buttonDraw(350, 350, 3, 3, window);
    buttons[5]->buttonDraw(350, 550, 3, 3, window);
}

void main_menu::mainMenuDraw(int screen, sf::RenderWindow& window){
    printf("MenuDRAW");
    window.clear();
    backgroundShape.setTexture(backgroundTexture[screen]);
    window.draw(backgroundShape);
    switch(screen){
        case 0:
            menuButtons(window);
            break;
        case 1:
            secondScrButtons(window);
            break;
        case 2:
            //thirdScrButtons(window);
            break;
    }
    if (screen==0)
        menuButtons(window);
    else
        menuButtons(window);
    //window.display();
}


int main_menu::mainButtons(sf::Event& event, sf::RenderWindow& window, int screen){
    std::cout<<screen<<std::endl;
    mainMenuDraw(screen, window);
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
                window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (screen==0){
                if (buttons[0]->isClicked(window)) {
                    std::cout << "Start button clicked!\n";
                    /*secondMenuDraw(window);
                    window.display();*/
                    return 1;
                    /*secButtons(event, window);
                    std::cout<<path[0]<<std::endl;*/
                }
                if (buttons[1]->isClicked(window)) {
                    window.close();
                }
            }
            else if (screen==1){
                if (buttons[3]->isClicked(window)) {
                    //std::cout << "!\n";
                    
                    window.display(); 
                    std::cout<<path[0]<<std::endl;
                }
            }
        }
    }
    return screen;
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
