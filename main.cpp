#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include "animation.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "AnimationDemo");

	sf::Sprite sprite;
	sf::IntRect rect(0, 0, 32, 32);
	animation::AnimationClip clip("Assets/Sprites/2.png", &sprite, rect);

	sf::Clock deltaClock;
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
        window.display();

        sf::Time dt = deltaClock.restart();
        //std::cout << "Delta time: " << dt.asMilliseconds() << std::endl;
        clip.Update(dt.asMilliseconds());
        //sprite.rotate(6);

    }

    return 0;
}
