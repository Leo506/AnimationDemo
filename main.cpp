#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include "animation.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "AnimationDemo");

	sf::Sprite sprite1, sprite2;  // Два спрайта для отображения

	// Создание анимации 1-ым способом
	sf::IntRect rect1(0, 0, 32, 32);
	animation::AnimationClip clip1("Assets/Sprites/2.png", &sprite1, rect1, 6);
	for (int i = 0; i < 6; i++)
		clip1.SetAnimTime(70 * (i+1), i);
	clip1.SetAnimSpeed(2);

	// Создание анимации 2-ым способом
	animation::AnimationClip clip2(&sprite2);
	clip2.SetNumberOfSprites(4);
	sf::Texture texture;
	for (int i = 0;  i < 4; i++)
	{
		sf::IntRect rect2(0 + 32 * i, 32, 32, 32);
		texture.loadFromFile("Assets/Sprites/2.png", rect2);
		clip2.SetTexture(texture, i);
		clip2.SetAnimTime(70 * (i + 1), i);
	}

	sprite1.setScale(3.0f, 3.0f);
	sprite2.setScale(3.0f, 3.0f);

	sprite1.setPosition(100, 252);
	sprite2.setPosition(604, 252);

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
        window.draw(sprite1);
        window.draw(sprite2);
        window.display();

        sf::Time dt = deltaClock.restart();
        clip1.Update(dt.asMilliseconds());
        clip2.Update(dt.asMilliseconds());

    }

    return 0;
}
