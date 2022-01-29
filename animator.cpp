#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "animator.h"
#include <cstring>

namespace animation
{
	Animator::Animator(sf::RenderWindow* const window, AnimationClip* clip)
	{
		m_window = window;
		m_clip  = clip;
		m_animationIsSet = true;
		m_speed = clip->AnimSpeed();
		m_rect = sf::IntRect(0,0,0,0);
		m_countOfSprites = clip->NumberOfSprites();
		ImGui::SFML::Init(*m_window);
	}

	Animator::Animator(sf::RenderWindow* const window)
	{
		m_window = window;
		m_clip = NULL;
		m_animationIsSet = false;
		m_speed = 0;
		m_rect = sf::IntRect(0,0,0,0);
		m_countOfSprites = 0;
		ImGui::SFML::Init(*m_window);
	}

	Animator::~Animator()
	{
		ImGui::SFML::Shutdown();
	}

	void Animator::ProcessEvent(const sf::Event& event)
	{
		ImGui::SFML::ProcessEvent(event);
	}

	void Animator::Render()
	{
		if (m_window != NULL && m_clip != NULL)
			ImGui::SFML::Render(*m_window);
	}

	void Animator::SetAnimClip(AnimationClip* clip)
	{
		m_clip = clip;
		m_animationIsSet = true;
		m_speed = clip->AnimSpeed();
		m_rect = sf::IntRect(0,0,0,0);
		m_countOfSprites = clip->NumberOfSprites();
		ImGui::SFML::Init(*m_window);
	}

	void Animator::Update(const sf::Time& deltaTime)
	{
		if (m_window != NULL && m_clip != NULL)
		{
			ImGui::SFML::Update(*m_window, deltaTime);

			ImGui::Begin("Animation Controller");

			ImGui::Text("Speed of animation");
			if (ImGui::DragFloat("Speed", &m_speed, 0.1f, 0.0f, 5.0f))
				m_clip->SetAnimSpeed(m_speed);

			if (ImGui::Button("Start"))
				m_clip->Restart();
			ImGui::SameLine();

			if (ImGui::Button("Pause"))
				m_clip->Pause(true);

			ImGui::SameLine();
			if (ImGui::Button("Unpause"))
				m_clip->Pause(false);

			static bool loop = true;
			if (ImGui::Checkbox("Loop", &loop))
				m_clip->SetLoop(loop);

			ImGui::End();
		}

	}
}
