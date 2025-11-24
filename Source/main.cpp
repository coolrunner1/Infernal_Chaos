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
                            "Sprites/lvl1_bg.png",
                            10,
                            "Sprites/lvl3_bg.png",
                            0,
                            new AmmoPacksContainer(15), 
                            new ArmorPacksContainer(15), 
                            new HealthPacksContainer(15), 
                            new NullEntitiesContainer,
                            new NullEntitiesContainer,
                            new NullEntitiesContainer,
                            new MobileEnemiesContainer(2), 
                            new ArmoredEnemiesContainer(5),
                            new CombinedEnemiesContainer(30, 0.5, 5),
                            new NullEnemiesContainer,
                            new NullEnemiesContainer,
                            new NullEnemiesContainer,
                            new BossContainer(1, 4)
                        );
                    }
                    break;
                case PS_LVL_1:
                    if (!mainLevel) {
                        mainLevel = new MainLevel(
                            "Sprites/lvl3_bg.png",
                            new AmmoPacksContainer(15), 
                            new ArmorPacksContainer(15), 
                            new HealthPacksContainer(15), 
                            new NullEntitiesContainer,
                            new NullEntitiesContainer,
                            new NullEntitiesContainer,
                            new MobileEnemiesContainer(2), 
                            new ArmoredEnemiesContainer(5),
                            new NullEnemiesContainer(),
                            new NullEnemiesContainer,
                            new NullEnemiesContainer,
                            new NullEnemiesContainer
                        );
                    }
                    break;
                case PS_LVL_2:
                    if (!mainLevel) {
                        mainLevel = new MainLevel(
                            "Sprites/lvl1_bg.png",
                            new AmmoPacksContainer(25), 
                            new ArmorPacksContainer(25), 
                            new HealthPacksContainer(25),
                            new NullEntitiesContainer,
                            new NullEntitiesContainer,
                            new NullEntitiesContainer,
                            new MobileEnemiesContainer(1),  
                            new ArmoredEnemiesContainer(5),
                            new CombinedEnemiesContainer(15, 0.7, 3),
                            new NullEnemiesContainer,
                            new NullEnemiesContainer,
                            new NullEnemiesContainer
                        );
                    }
                    break;
                case PS_LVL_3:
                    if (!mainLevel) {
                        mainLevel = new MainLevel(
                            "Sprites/lvl2_bg.png",
                            new AmmoPacksContainer(35), 
                            new NullEntitiesContainer, 
                            new HealthPacksContainer(35),
                            new NullEntitiesContainer,
                            new NullEntitiesContainer,
                            new NullEntitiesContainer, 
                            new ArmoredEnemiesContainer(0.5),
                            new CombinedEnemiesContainer(1, 0.7, 3), 
                            new BossContainer(0.7, 2),
                            new NullEnemiesContainer,
                            new NullEnemiesContainer,
                            new NullEnemiesContainer
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