#include <SFML/Graphics.hpp>
#include <iostream>
#include "mainMenu.hpp"
#include "button.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Infernal Chaos");
    //sf::CircleShape shape(100.f);
    sf::Image icon;
    icon.loadFromFile("Sprites/logo.png"); // File/Image/Pixel
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::Texture texture;
    if (!texture.loadFromFile("Sprites/rascal.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    //shape.setFillColor(sf::Color::Green);
    main_menu main1;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
                if (mainMenu.startButton.isClicked(window)) {
                    std::cout << "Start button clicked!\n";
                    // Add code to handle button click action
                }
            }
        window.clear();
        main1.mainMenuDraw(window);
        window.display();
        //if (main1)
        //
        //window.draw(sprite);
        //window.draw(texture);
        //window.draw(shape);
        //
    }

    return 0;
}