#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Infernal Chaos");
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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        //window.draw(texture);
        //window.draw(shape);
        window.display();
    }

    return 0;
}