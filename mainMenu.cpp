#include "mainMenu.hpp"

main_menu::main_menu() {
    if (!backgroundTexture.loadFromFile("Sprites/main_menu.png")) {
        std::cerr << "Missing file: Sprites/main_menu.png\n";
    }
    path[0]="Sprites/Play.png";
    path[1]="Sprites/quit.png";
    path[2]="Sprites/infernal_campaign.png";
    path[3]="Sprites/perpetual_suffering.png";
    path[4]="Sprites/back.png";
    backgroundShape.setTexture(backgroundTexture);
    //buttons[0]={button(path[0])};
    for (int i=0; i<numOfButtons; i++)
        buttons[i] = new button {button(path[i])};
}

main_menu::~main_menu(){
    for (int i=0; i<numOfButtons; i++)
        delete buttons[i];
}

void main_menu::menuButtons(int min, int max, sf::RenderWindow& window){
    for (int i=min; i<=max; i++){
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

/*int main_menu::secButtons(sf::Event& event, sf::RenderWindow& window){
    std::cout<<"ENTERED SECBUTT\n";
    mainMenuDraw(1, window);
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
                window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
                if (buttons[3]->isClicked(window)) {
                    //std::cout << "GAY!\n";
                    
                    window.display(); 
                    std::cout<<path[0]<<std::endl;
                }
                /*if (buttons[1]->isClicked(window)) {
                    window.close();
                }*/
        /*}
    }
    return 0;
}*/
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