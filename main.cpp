#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include "animation.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "animator.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "AnimationDemo");
	ImGui::SFML::Init(window);

	float speed = 1;

	sf::Sprite sprite1, sprite2;

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
		if (!clip2.SetAnimTime(70 * (i+1), i))
		{
			std::cout << "Error on create anim clip\n";
			return -1;
		}
		sf::IntRect rect2(0 + 32 * i, 32, 32, 32);
		texture.loadFromFile("Assets/Sprites/2.png", rect2);
		clip2.SetTexture(texture, i);
		clip2.SetAnimTime(70 * (i + 1), i);
	}
	std::cout << "Anim time is setted\n";
	//sprite.setScale(3.0f, 3.0f);
	//sprite.setPosition(400 - sprite.getGlobalBounds().width / 2, 300 - sprite.getGlobalBounds().height / 2);

	sprite1.setScale(3.0f, 3.0f);
	sprite2.setScale(3.0f, 3.0f);

	sprite1.setPosition(100, 252);
	sprite2.setPosition(604, 252);

	animation::Animator animator(&window);

	sf::Clock deltaClock;
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
        	animator.ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        	sf::Vector2i mousePos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        	if (sprite1.getGlobalBounds().contains(mousePos.x, mousePos.y))
			{
				animator.SetAnimClip(&clip1);
			}
			else if (sprite2.getGlobalBounds().contains(mousePos.x, mousePos.y))
				animator.SetAnimClip(&clip2);
        }

        sf::Time dt = deltaClock.restart();

        animator.Update(dt);

        clip1.Update(dt.asMilliseconds());
        clip2.Update(dt.asMilliseconds());

        window.clear();
        window.draw(sprite1);
        window.draw(sprite2);
        animator.Render();
        window.display();

    }

    return 0;
}
