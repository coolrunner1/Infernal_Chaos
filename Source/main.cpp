#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Menu/mainMenu.hpp"
//#include "Menu/Entities/player.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Infernal Chaos");
    //sf::CircleShape shape(100.f);
    sf::Image icon;
    icon.loadFromFile("Sprites/logo.png"); // File/Image/Pixel
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::Texture texture;
    /*if (!texture.loadFromFile("Sprites/rascal.png"))
    {
        return EXIT_FAILURE;
    }*/
    /*sf::Music music;
    if (!music.openFromFile("music.ogg")){
        std::cerr<<"Missing audio file: track_menu.wav\n";
    }
    music.play();*/
    sf::Sprite sprite(texture);
    //shape.setFillColor(sf::Color::Green);
    main_menu* main1 = new main_menu;
    //levelPattern* temp = new levelPattern;
    //main_menu main1;
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
        //std::cout<<menuChoice<<std::endl;
        menuChoice=main1->mainButtons(event, window, menuChoice);
        if (menuChoice<INFERNAL_CAMPAIGN){
            window.setFramerateLimit(10);
        }
        else{
            window.setFramerateLimit(60);
            //temp->levelRender(event, window);
        }
        
        /*switch(menuChoice){
            case 0:
                menuChoice=main1->mainButtons(event, window, 0);
                //std::cout<<menuChoice<<std::endl;
                break;
            case 1:
                menuChoice=main1->mainButtons(event, window, 1);
                //main1->secButtons(event, window);
                break;
            default:
                delete main1;
                return 0;
                break;
        }*/
        //main1.mainButtons(event, window);
        window.display();
        //if (main1)
        //
        //window.draw(sprite);
        //window.draw(texture);
        //window.draw(shape);
        //
    }
}