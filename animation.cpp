#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"

namespace animation
{
	AnimationClip::AnimationClip(std::string path, sf::Sprite* sprite, sf::IntRect& rect, int countOfSprites) : m_lostTime(0), m_current(0)
	{
		m_numberOfSprites = countOfSprites;

		// Загрузка текстур
		for (int i = 0; i < countOfSprites; i++)
		{
			// Создание новой текстуры
			m_textures.push_back(new sf::Texture);

			// Характеристка текстуры
			sf::IntRect spriteRect(0 + i * rect.width, 0, rect.width, rect.height);
			if (!m_textures[i]->loadFromFile(path, spriteRect))
			{
				std::cout << "Error on loading sprite\n";
				std::exit(-3);
			}
		}

		// Анимируемый спрайт в m_currentSprite
		m_currentSprite = sprite;

		// Установка текстуры
		m_currentSprite->setTexture(*m_textures[m_current]);

		std::cout << "Animation clip is created\n";
	}


	AnimationClip::AnimationClip(const AnimationClip& animClip)
	{
		m_numberOfSprites = animClip.m_numberOfSprites;
		m_current = animClip.m_current;
		m_lostTime = animClip.m_lostTime;

		for (int i = 0; i < m_numberOfSprites; i++)
			m_textures.push_back(new sf::Texture(*animClip.m_textures[i]));

		for (int i = 0; i < m_numberOfSprites; i++)
			m_animTimes.push_back(animClip.m_animTimes[i]);
	}


	AnimationClip& AnimationClip::operator=(const AnimationClip& animClip)
	{
		if (this == & animClip)
			return *this;

		m_numberOfSprites = animClip.m_numberOfSprites;
		m_current = animClip.m_current;
		m_lostTime = animClip.m_lostTime;

		m_textures.clear();
		for (int i = 0; i < m_numberOfSprites; i++)
			m_textures.push_back(new sf::Texture(*animClip.m_textures[i]));

		m_animTimes.clear();
		for (int i = 0; i < m_numberOfSprites; i++)
			m_animTimes.push_back(animClip.m_animTimes[i]);

		return *this;
	}


	bool AnimationClip::SetAnimTime(long int time, int index)
	{
		std::cout << "Index: " << index << " Value: " << time << std::endl;
		if (index < 0 || index >= m_numberOfSprites)
			return false;

		m_animTimes.insert(m_animTimes.begin() + index, time);
		std::cout << "Anim time " << time << " set in position by " << index << " index\n";
		return true;
	}


	void AnimationClip::Update(int delta)
	{
		if (m_animTimes.size() != 0)
		{

			m_lostTime += delta;
			if (m_lostTime >= m_animTimes[m_current])
			{
				m_current++;
				if (m_current >= 6)
				{
					m_current = 0;
					m_lostTime = 0;
				}

				m_currentSprite->setTexture(*m_textures[m_current]);
				std::cout << "Current sprite index: " << m_current << std::endl;
			}
		}
	}


	AnimationClip::~AnimationClip()
	{
		for (int i = 0; i < m_numberOfSprites; i++)
			delete m_textures[i];
	}
}
