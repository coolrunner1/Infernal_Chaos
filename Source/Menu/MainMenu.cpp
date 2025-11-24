#include "MainMenu.hpp"

MainMenu::MainMenu() {
    if (!backgroundTexture[0].loadFromFile("Sprites/main_menu.png")) {
        std::cerr << "Missing file: Sprites/main_menu.png\n";
    }
    if (!backgroundTexture[1].loadFromFile("Sprites/menu1.png")) {
        std::cerr << "Missing file: Sprites/menu1.png\n";
    }
    if (!backgroundTexture[2].loadFromFile("Sprites/menu2.png")) {
        std::cerr << "Missing file: Sprites/menu2.png\n";
    }
    path[0] = "Sprites/infernal_chaos_title.png";
    path[1] = "Sprites/Play.png";
    path[2] = "Sprites/quit.png";
    path[3] = "Sprites/infernal_campaign.png";
    path[4] = "Sprites/perpetual_suffering.png";
    path[5] = "Sprites/back.png";
    path[6] = "Sprites/level_1.png";
    path[7] = "Sprites/level_2.png";
    path[8] = "Sprites/level_3.png";
    path[9] = "Sprites/game_mode.png";
    for (int i = 0; i < numOfButtons; i++)
        buttons[i] = new Button {Button(path[i])};
}

MainMenu::~MainMenu(){
    for (int i=0; i<numOfButtons; i++)
        delete buttons[i];
}

void MainMenu::menuButtons(sf::RenderWindow& window){
    buttons[INFERNAL_CHAOS_TITLE]->buttonDraw(50, 50, 6, 6, window);
	buttons[PLAY_BUTTON]->buttonDraw(350, 250, 10, 10, window);
    buttons[QUIT_BUTTON]->buttonDraw(350, 500, 10, 10, window);
}

void MainMenu::secondScrButtons(sf::RenderWindow& window){
    buttons[GAMEMODE_SPRITE]->buttonDraw(280, 50, 6, 6, window);
    buttons[INFERNAL_CAMPAIGN_BUTTON]->buttonDraw(150, 300, 4, 4, window);
    buttons[PERPETUAL_SUFFERING_BUTTON]->buttonDraw(100, 450, 4, 4, window);
    buttons[BACK_BUTTON]->buttonDraw(500, 600, 5, 5, window);
}

void MainMenu::thirdScrButtons(sf::RenderWindow& window){
    buttons[PERPETUAL_SUFFERING_BUTTON]->buttonDraw(100, 50, 4, 4, window);
    buttons[LEVEL_1_BUTTON]->buttonDraw(350, 250, 3, 3, window);
    buttons[LEVEL_2_BUTTON]->buttonDraw(350, 350, 3, 3, window);
    buttons[LEVEL_3_BUTTON]->buttonDraw(350, 450, 3, 3, window);
    buttons[BACK_BUTTON]->buttonDraw(350, 550, 3, 3, window);
}

void MainMenu::mainMenuDraw(int screen, sf::RenderWindow& window, sf::Event& event){
    window.clear();
    window.setMouseCursorVisible(true);
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
}


int MainMenu::render(sf::Event& event, sf::RenderWindow& window, int screen){
    mainMenuDraw(screen, window, event);
        if (event.type == sf::Event::MouseButtonPressed) {
            switch (screen){
                case MAIN_MENU:
                    if (buttons[PLAY_BUTTON]->isClicked(window)) {
                        return PLAY_MENU;
                    }
                    if (buttons[QUIT_BUTTON]->isClicked(window)) {
                        window.close();
                    }
                    break;
                case PLAY_MENU:
                    if (buttons[INFERNAL_CAMPAIGN_BUTTON]->isClicked(window)) {
                        return INFERNAL_CAMPAIGN;
                    }
                    if (buttons[PERPETUAL_SUFFERING_BUTTON]->isClicked(window)) {
                        return PERPETUAL_SUFFERING_MENU;
                    }
                    if (buttons[BACK_BUTTON]->isClicked(window)) {
                        return MAIN_MENU;
                    }
                    break;
                case PERPETUAL_SUFFERING_MENU:
                    if (buttons[LEVEL_1_BUTTON]->isClicked(window)) {
                        return PS_LVL_1;
                    }
                    if (buttons[LEVEL_2_BUTTON]->isClicked(window)) {
                        return PS_LVL_2;
                    }
                    if (buttons[LEVEL_3_BUTTON]->isClicked(window)) {
                        return PS_LVL_3;
                    }
                    if (buttons[BACK_BUTTON]->isClicked(window)) {
                        return PLAY_MENU;
                    }
                    break;
            }
        }
    return screen;
}