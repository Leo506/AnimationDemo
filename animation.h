#ifndef ANIMATION_H_
#define ANIMATION_H_
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

namespace animation
{
	class AnimationClip
	{
	private:
		std::vector<sf::Texture*> m_textures;          // Спрайты (текстуры) анимации
		sf::Sprite* m_currentSprite;                   // Анимируемый спрайт
		long int m_lostTime;                           // Прошедшее время
		int m_current;                                 // Индекс текущей текстуры
		std::vector<long int> m_animTimes;             // Время смены спрайтов
		int m_numberOfSprites;                         // Количество спрайтов в анимации
		float m_animSpeed;                             // Скорость анимации
		bool m_pause;                                  // Состояние анимации (на паузе или нет)

		void UpdateAnimTimes();                        // Обновляет время смены анимации при изменении скорости

	public:

		// Конструктор
		// path - путь к файлу со спрайтами
		// sprite - анимируемый спрайт
		// rect - характеристика первого спрайта в наборе (координаты верхнего левого угла, ширина и высота)
		// countsOfSprites - кол-во спрайтов в анимации
		AnimationClip(std::string path, sf::Sprite* sprite, sf::IntRect& rect, int countOfSprites);

		// Конструктор по-умолчанию
		AnimationClip(sf::Sprite* sprite);

		// Конструктор копирования
		AnimationClip(const AnimationClip& animClip);

		// Оператор присваивания
		AnimationClip& operator=(const AnimationClip& animClip);

		// Деструктор
		~AnimationClip();

		// Установка времени смены спрайтов
		// time - время смены в миллисекундах после начала анимации
		// index - индекс времени (порядковый номер)
		bool SetAnimTime(long int time, int index);

		// Установка текстуры спрайта
		// texture - ссылка на текстуру
		// index - индекс текстуры (порядковый номер)
		bool SetTexture(sf::Texture& texture, int index);

		// Устанавливает кол-во спрайтов в анимации
		void SetNumberOfSprites(int value) { m_numberOfSprites = value; }

		// Установка скорости анимации
		void SetAnimSpeed(float speed) { m_animSpeed = speed; }

		// Возвращает кол-во спрайтов в анимации
		const int NumberOfSprites() const { return m_numberOfSprites; }

		// Возвращает скорость анимации
		const float AnimSpeed() const { return m_animSpeed; }

		// Обновить анимацию
		void Update(int delta);

		// Пауза анимации
		void Pause(bool pause) { m_pause = pause; }
	};
}

#endif // ANIMATION_H_
