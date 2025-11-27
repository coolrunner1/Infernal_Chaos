#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu/MainMenu.hpp"
#include "Levels/Factories/EasyPerpetualLevelFactory.hpp"
#include "Levels/Factories/MediumPerpetualLevelFactory.hpp"
#include "Levels/Factories/HardPerpetualLevelFactory.hpp"
#include "Levels/Factories/FirstCampaignLevelFactory.hpp"
#include "Levels/Factories/LevelConfigurator.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Infernal Chaos");
    sf::Image icon;
    icon.loadFromFile("Sprites/logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    MainMenu* mainMenu = new MainMenu;
    MainLevel* mainLevel = nullptr;
    LevelConfigurator levelConfigurator;
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
            menuChoice=mainMenu->render(event, window, menuChoice);
        }
        else if (menuChoice<7){
            window.setFramerateLimit(60);
            switch(menuChoice){
                case INFERNAL_CAMPAIGN:
                    if (!mainLevel) {
                        FirstCampaignLevelFactory* factory = new FirstCampaignLevelFactory;
                        mainLevel = levelConfigurator.getCampaignLevel(*factory);
                        delete factory;
                    }
                    delete mainMenu;
                    mainMenu = nullptr;
                    break;
                case PS_LVL_1:
                    if (!mainLevel) {
                        EasyPerpetualLevelFactory* factory = new EasyPerpetualLevelFactory;
                        mainLevel = levelConfigurator.getPerpetualLevel(*factory);
                        delete factory;
                    }
                    delete mainMenu;
                    mainMenu = nullptr;
                    break;
                case PS_LVL_2:
                    if (!mainLevel) {
                        MediumPerpetualLevelFactory* factory = new MediumPerpetualLevelFactory;
                        mainLevel = levelConfigurator.getPerpetualLevel(*factory);
                        delete factory;
                    }
                    delete mainMenu;
                    mainMenu = nullptr;
                    break;
                case PS_LVL_3:
                    if (!mainLevel) {
                        HardPerpetualLevelFactory* factory = new HardPerpetualLevelFactory;
                        mainLevel = levelConfigurator.getPerpetualLevel(*factory);
                        delete factory;
                    }
                    delete mainMenu;
                    mainMenu = nullptr;
                    break;
            }
            menuChoice=7;
        }
        else{
            if (mainLevel) {
                menuChoice=mainLevel->render(event, window);
            }
        }
        window.display();
    }
}