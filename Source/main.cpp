#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu/mainMenu.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Infernal Chaos");
    sf::Image icon;
    icon.loadFromFile("Sprites/logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    main_menu* main1 = new main_menu;
    mainLevel* level = new mainLevel;
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
            menuChoice=main1->mainButtons(event, window, menuChoice);
        }
        else if (menuChoice<7){
            window.setFramerateLimit(60);
            switch(menuChoice){
                case INFERNAL_CAMPAIGN:
                    level->setCampaign();
                    break;
                case PS_LVL_1:
                    level->setEasyDifficulty();
                    break;
                case PS_LVL_2:
                    level->setMediumDifficulty();
                    break;
                case PS_LVL_3:
                    level->setHardDifficulty();
                    break;
            }
            menuChoice=7;
        }
        else{
            menuChoice=level->levelRender(event, window);
        }
        window.display();
    }
}