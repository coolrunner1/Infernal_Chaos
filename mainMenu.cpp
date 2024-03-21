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
    path[6]="Sprites/level_1.png";
    path[7]="Sprites/level_2.png";
    path[8]="Sprites/level_3.png";
    path[9]="Sprites/game_mode.png";
    for (int i=0; i<numOfButtons; i++)
        buttons[i] = new button {button(path[i])};
}

main_menu::~main_menu(){
    for (int i=0; i<numOfButtons; i++)
        delete buttons[i];
}

void main_menu::menuButtons(sf::RenderWindow& window){
    buttons[0]->buttonDraw(50, 50, 6, 6, window);
	buttons[1]->buttonDraw(350, 250, 10, 10, window);
    buttons[2]->buttonDraw(350, 500, 10, 10, window);
}

void main_menu::secondScrButtons(sf::RenderWindow& window){
    buttons[9]->buttonDraw(280, 50, 6, 6, window);
    buttons[3]->buttonDraw(150, 300, 4, 4, window);
    buttons[4]->buttonDraw(100, 450, 4, 4, window);
    buttons[5]->buttonDraw(500, 600, 5, 5, window);
}

void main_menu::thirdScrButtons(sf::RenderWindow& window){
    buttons[4]->buttonDraw(100, 50, 4, 4, window);
    buttons[6]->buttonDraw(350, 250, 3, 3, window);
    buttons[7]->buttonDraw(350, 350, 3, 3, window);
    buttons[8]->buttonDraw(350, 450, 3, 3, window);
    buttons[5]->buttonDraw(350, 550, 3, 3, window);
}

void main_menu::mainMenuDraw(int screen, sf::RenderWindow& window){
    window.clear();
    backgroundShape.setTexture(backgroundTexture[screen]);
    window.draw(backgroundShape);
    switch(screen){
        case MAIN_MENU:
            menuButtons(window);
            break;
        case PLAY_MENU:
            secondScrButtons(window);
            break;
        case PERPETUAL_SUFFERING_MENU:
            thirdScrButtons(window);
            break;
    }
    /*if (screen==0)
        menuButtons(window);
    else
        menuButtons(window);*/
    //window.display();
}


int main_menu::mainButtons(sf::Event& event, sf::RenderWindow& window, int screen){
    mainMenuDraw(screen, window);
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
                window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            switch (screen){
                case MAIN_MENU:
                    if (buttons[1]->isClicked(window)) {
                        return PLAY_MENU;
                    }
                    if (buttons[2]->isClicked(window)) {
                        window.close();
                    }
                    break;
                case PLAY_MENU:
                    if (buttons[3]->isClicked(window)) {
                        return INFERNAL_CAMPAIGN;
                    }
                    if (buttons[4]->isClicked(window)) {
                        return PERPETUAL_SUFFERING_MENU;
                    }
                    if (buttons[5]->isClicked(window)) {
                        return MAIN_MENU;
                    }
                    break;
                case PERPETUAL_SUFFERING_MENU:
                    if (buttons[5]->isClicked(window)) {
                        return PLAY_MENU;
                    }
                    break;
                case INFERNAL_CAMPAIGN:
                    std::cout<<"Placeholder\n";
                    break;
                case PS_LVL_1:
                    break;
                case PS_LVL_2:
                    break;
                case PS_LVL_3:
                    break;
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
