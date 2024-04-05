#include "menu.hpp"

menu::menu() {
    if (!backgroundTexture.loadFromFile("Sprites/main_menu_old.png")) {
        std::cerr << "Missing file: Sprites/main_menu_old.png\n";
    }
}

menu::menu(std::string backPath, std::string butPath[], int butNum) {
    if (!backgroundTexture.loadFromFile("Sprites/main_menu_old.png")) {
        std::cerr << "Missing file: "<<backPath<<std::endl;
    }
    numOfbuttons=butNum;
    /*path[0]="Sprites/Play.png";
    path[1]="Sprites/quit.png";
    path[2]="Sprites/infernal_campaign.png";
    path[3]="Sprites/perpetual_suffering.png";
    path[4]="Sprites/back.png";*/
    //buttons[0]={button(path[0])};
    for (int i=0; i<numOfbuttons; i++){
        path[i]=butPath[i];
        buttons[i] = new button {button(path[i])};
    }
}
menu::~menu(){
    for (int i=0; i<numOfbuttons; i++)
        delete buttons[i];
}

void menu::menuButtons(sf::RenderWindow& window){
    for (int i=0; i<=numOfbuttons; i++){
        switch(i){
            case 0:
                buttons[0]->buttonDraw(350, 50, 10, 10, window);
                break;
            case 1:
                buttons[1]->buttonDraw(350, 500, 10, 10, window);
                break;
            case 2:
                buttons[2]->buttonDraw(350, 50, 3, 3, window);
                break;
            case 3:
                buttons[3]->buttonDraw(350, 350, 3, 3, window);
                break;
            case 4:
                buttons[4]->buttonDraw(350, 550, 3, 3, window);
                break;
        }
    }
}

void main_menu::mainMenuDraw(int screen, sf::RenderWindow& window){
    window.clear();
    backgroundShape.setTexture(backgroundTexture[screen]);
    window.draw(backgroundShape);
    if (screen==0)
        menuButtons(0, 1, window);
    else
        menuButtons(2, 4, window);
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
                    //std::cout << "GAY!\n";
                    
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