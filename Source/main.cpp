#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu/MainMenu.hpp"
#include "EntityContainers/AmmoPacksContainer.hpp"
#include "EntityContainers/ArmorPacksContainer.hpp"
#include "EntityContainers/HealthPacksContainer.hpp"
#include "EntityContainers/MobileEnemiesContainer.hpp"
#include "EntityContainers/ArmoredEnemiesContainer.hpp"
#include "EntityContainers/CombinedEnemiesContainer.hpp"
#include "EntityContainers/NullEnemiesContainer.hpp"
#include "EntityContainers/NullEntitiesContainer.hpp"
#include "EntityContainers/BossContainer.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Infernal Chaos");
    sf::Image icon;
    icon.loadFromFile("Sprites/logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    MainMenu* mainMenu = new MainMenu;
    MainLevel* mainLevel = nullptr;
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
                    if (!mainLevel) {
                        mainLevel = new MainLevel(
                            CAMPAIGN,
                            "Sprites/lvl1_bg.png",
                            new AmmoPacksContainer, 
                            new ArmorPacksContainer, 
                            new HealthPacksContainer, 
                            new MobileEnemiesContainer, 
                            new ArmoredEnemiesContainer,
                            new CombinedEnemiesContainer(0.5, 5),
                            new BossContainer(1, 4)
                        );
                    }
                    break;
                case PS_LVL_1:
                    if (!mainLevel) {
                        mainLevel = new MainLevel(
                            SUFFERING_EASY,
                            "Sprites/lvl3_bg.png",
                            new AmmoPacksContainer, 
                            new ArmorPacksContainer, 
                            new HealthPacksContainer, 
                            new MobileEnemiesContainer, 
                            new ArmoredEnemiesContainer,
                            new NullEnemiesContainer(),
                            new NullEnemiesContainer()
                        );
                    }
                    break;
                case PS_LVL_2:
                    if (!mainLevel) {
                        mainLevel = new MainLevel(
                            SUFFERING_MEDIUM,
                            "Sprites/lvl1_bg.png",
                            new AmmoPacksContainer, 
                            new ArmorPacksContainer, 
                            new HealthPacksContainer,
                            new MobileEnemiesContainer,  
                            new ArmoredEnemiesContainer,
                            new CombinedEnemiesContainer(0.7, 3),
                            new NullEnemiesContainer()
                        );
                    }
                    break;
                case PS_LVL_3:
                    if (!mainLevel) {
                        mainLevel = new MainLevel(
                            SUFFERING_HARD,
                            "Sprites/lvl2_bg.png",
                            new AmmoPacksContainer, 
                            new NullEntitiesContainer, 
                            new HealthPacksContainer, 
                            new ArmoredEnemiesContainer,
                            new CombinedEnemiesContainer(0.7, 3), 
                            new BossContainer(0.7, 2),
                            new NullEnemiesContainer()
                        );
                    }
                    break;
            }
            menuChoice=7;
        }
        else{
            if (mainLevel) {
                menuChoice=mainLevel->levelRender(event, window);
            }
        }
        window.display();
    }
}


/*#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu/MainMenu.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Infernal Chaos");
    sf::Image icon;
    icon.loadFromFile("Sprites/logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    MainMenu* mainMenu = new MainMenu;
    MainLevel* mainLevel;
    int menuChoice=MAIN_MENU;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (menuChoice < INFERNAL_CAMPAIGN){
            window.setFramerateLimit(5);
            menuChoice = mainMenu->mainButtons(event, window, menuChoice);
        } else if (menuChoice < 7){
            if (!mainLevel) {
                mainLevel = new MainLevel();
            }

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
            menuChoice = 7;
        } else {
            menuChoice = mainLevel->levelRender(event, window);

          
        }

        window.display();
    }
}*/