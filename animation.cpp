#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"

namespace animation
{
	AnimationClip::AnimationClip(std::string path, sf::Sprite* sprite, sf::IntRect& rect, int countOfSprites) : m_lostTime(0), m_current(0), m_animSpeed(1), m_pause(false)
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


	// Конструктор по умолчанию
	// Устанавливает все члены класса в дефолтные значения
	AnimationClip::AnimationClip(sf::Sprite* sprite)
	{
		m_lostTime = 0;
		m_current = 0;
		m_numberOfSprites = 0;
		m_animSpeed = 1;
		m_currentSprite = sprite;
		m_pause = false;
	}


	AnimationClip::AnimationClip(const AnimationClip& animClip)
	{
		// Копирование обычных членов класса
		m_numberOfSprites = animClip.m_numberOfSprites;
		m_current = animClip.m_current;
		m_lostTime = animClip.m_lostTime;

		// Копирование загруженных текстур
		for (int i = 0; i < m_numberOfSprites; i++)
			m_textures.push_back(new sf::Texture(*animClip.m_textures[i]));

		// Копирование
		for (int i = 0; i < m_numberOfSprites; i++)
			m_animTimes.push_back(animClip.m_animTimes[i]);
	}


	AnimationClip& AnimationClip::operator=(const AnimationClip& animClip)
	{
		// Проверяем на присваивание самому себе
		if (this == & animClip)
			return *this;

		// Копируем обычные члены класса
		m_numberOfSprites = animClip.m_numberOfSprites;
		m_current = animClip.m_current;
		m_lostTime = animClip.m_lostTime;

		// Чистим уже загруженные текстуры
		for (int i = 0; i < m_textures.size(); i++)
			delete m_textures[i];

		// Копирование загруженных текстур
		for (int i = 0; i < m_numberOfSprites; i++)
			m_textures.push_back(new sf::Texture(*animClip.m_textures[i]));

		// Сбрасываем вектор m_animTimes
		// и копируем в него новые значения
		m_animTimes.clear();
		for (int i = 0; i < m_numberOfSprites; i++)
			m_animTimes.push_back(animClip.m_animTimes[i]);

		return *this;
	}


	bool AnimationClip::SetAnimTime(long int time, int index)
	{
		// Проверка на корректность индекса
		if (index < 0 || index >= m_numberOfSprites)
			return false;

		m_animTimes.insert(m_animTimes.begin() + index, time);
		return true;
	}


	bool AnimationClip::SetTexture(sf::Texture& texture, int index)
	{
		if (index < 0 || index >= m_numberOfSprites)
			return false;

		m_textures.insert(m_textures.begin() + index, new sf::Texture(texture));
		return true;
	}


	void AnimationClip::UpdateAnimTimes()
	{
		for (int i = 0; i < m_animTimes.size(); i++)
		{
			m_animTimes[i] /= m_animSpeed;
		}
	}


	void AnimationClip::Update(int delta)
	{
		if (m_animTimes.size() != 0 && !m_pause)
		{

			m_lostTime += delta;
			if (m_lostTime >= m_animTimes[m_current] / m_animSpeed)
			{
				m_current++;
				if (m_current >= m_numberOfSprites)
				{
					m_current = 0;
					m_lostTime = 0;
				}

				m_currentSprite->setTexture(*m_textures[m_current]);
			}
		}
	}


	AnimationClip::~AnimationClip()
	{
		for (int i = 0; i < m_numberOfSprites; i++)
			delete m_textures[i];
	}
}
