#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include "animation.h"
#include "imgui.h"
#include "imgui-SFML.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "AnimationDemo");
	ImGui::SFML::Init(window);

	float speed = 1;

	sf::Sprite sprite1;

	// Создание анимации 1-ым способом
	sf::IntRect rect1(0, 0, 32, 32);
	animation::AnimationClip clip1("Assets/Sprites/2.png", &sprite1, rect1, 6);
	for (int i = 0; i < 6; i++)
		clip1.SetAnimTime(70 * (i+1), i);
	clip1.SetAnimSpeed(2);

	sprite1.setScale(3.0f, 3.0f);

	sprite1.setPosition(100, 252);

	sf::Clock deltaClock;
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
        	ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time dt = deltaClock.restart();

        ImGui::SFML::Update(window, dt);

        ImGui::Begin("Animation Controller");

        ImGui::Text("Speed of animation");
        ImGui::SliderFloat("speed", &speed, 0.0f, 5.0f);
        if (ImGui::Button("Set speed"))
			clip1.SetAnimSpeed(speed);
		if (ImGui::Button("Pause"))
			clip1.Pause(true);
		if (ImGui::Button("Unpause"))
			clip1.Pause(false);
		ImGui::End();

        clip1.Update(dt.asMilliseconds());

        window.clear();
        window.draw(sprite1);
        ImGui::SFML::Render(window);
        window.display();

    }

    ImGui::SFML::Shutdown();

    return 0;
}
