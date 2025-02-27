#ifndef SFML_MAINMENU
#define SFML_MAINMENU
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Button.hpp"
#include "../Levels/MainLevel.hpp"
#define numOfButtons 10
#define MAIN_MENU 0
#define PLAY_MENU 1
#define INFERNAL_CAMPAIGN 3
#define PERPETUAL_SUFFERING_MENU 2
#define PS_LVL_1 4
#define PS_LVL_2 5
#define PS_LVL_3 6
#define INFERNAL_CHAOS_TITLE 0
#define PLAY_BUTTON 1
#define QUIT_BUTTON 2
#define INFERNAL_CAMPAIGN_BUTTON 3
#define PERPETUAL_SUFFERING_BUTTON 4
#define BACK_BUTTON 5
#define LEVEL_1_BUTTON 6
#define LEVEL_2_BUTTON 7
#define LEVEL_3_BUTTON 8
#define GAMEMODE_SPRITE 9

class MainMenu {
    private:
        sf::Texture backgroundTexture[4];
        sf::Sprite backgroundShape;
        std::string path[numOfButtons];
        Button* buttons[numOfButtons];
    public:
        void mainMenuDraw(int screen, sf::RenderWindow& window, sf::Event& event);
        int mainButtons(sf::Event& event, sf::RenderWindow& window, int screen);
        void menuButtons(sf::RenderWindow& window);
        void secondScrButtons(sf::RenderWindow& window);
        void thirdScrButtons(sf::RenderWindow& window);
        MainMenu();
        ~MainMenu();
};
#endif
