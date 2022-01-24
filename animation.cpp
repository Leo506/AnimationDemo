#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"

namespace animation
{
	AnimationClip::AnimationClip(std::string path, sf::Sprite* sprite, sf::IntRect& rect) : m_lostTime(0), m_current(0)
	{
		for (int i = 0; i < 6; i++)
		{
			m_sprite[i] = new sf::Texture;

			sf::IntRect spriteRect(0 + i * rect.width, 0, rect.width, rect.height);
			if (!m_sprite[i]->loadFromFile(path, spriteRect))
			{
				std::cout << "Error on loading sprite\n";
				break;
			}
		}
		m_currentSprite = sprite;
		m_currentSprite->setScale(3.0f, 3.0f);
		m_currentSprite->setPosition(400 - m_currentSprite->getGlobalBounds().width / 2, 300 - m_currentSprite->getGlobalBounds().height / 2);
		m_currentSprite->setTexture(*m_sprite[m_current]);
	}

	void AnimationClip::Update(int delta)
	{
		m_lostTime += delta;
		if (m_lostTime >= m_times[m_current])
		{
			m_current++;
			if (m_current >= 6)
			{
				m_current = 0;
				m_lostTime = 0;
			}
			std::cout << m_current << std::endl;
			m_currentSprite->setTexture(*m_sprite[m_current]);
		}
		std::cout << "lost time: " << m_lostTime << std::endl;
	}

	AnimationClip::~AnimationClip()
	{
		for (int i = 0; i < 3; i++)
			delete m_sprite[i];
	}
}
