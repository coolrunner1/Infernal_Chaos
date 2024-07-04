#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu/MainMenu.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Infernal Chaos");
    sf::Image icon;
    icon.loadFromFile("Sprites/logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    MainMenu* mainMenu = new MainMenu;
    MainLevel* mainLevel = new MainLevel;
    int menuChoice=MAIN_MENU;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (menuChoice<INFERNAL_CAMPAIGN){
            window.setFramerateLimit(5);
            menuChoice=mainMenu->mainButtons(event, window, menuChoice);
        }
        else if (menuChoice<7){
            window.setFramerateLimit(60);
            switch(menuChoice){
                case INFERNAL_CAMPAIGN:
                    mainLevel->setCampaign();
                    break;
                case PS_LVL_1:
                    mainLevel->setEasyDifficulty();
                    break;
                case PS_LVL_2:
                    mainLevel->setMediumDifficulty();
                    break;
                case PS_LVL_3:
                    mainLevel->setHardDifficulty();
                    break;
            }
            menuChoice=7;
        }
        else{
            menuChoice=mainLevel->levelRender(event, window);
        }
        window.display();
    }
}