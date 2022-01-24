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

	public:

		// Конструктор
		// path - путь к файлу со спрайтами
		// sprite - анимируемый спрайт
		// rect - характеристика первого спрайта в наборе (координаты верхнего левого угла, ширина и высота)
		// countsOfSprites - кол-во спрайтов в анимации
		AnimationClip(std::string path, sf::Sprite* sprite, sf::IntRect& rect, int countOfSprites);
		AnimationClip(const AnimationClip& animClip);
		AnimationClip& operator=(const AnimationClip& animClip);
		~AnimationClip();

		bool SetAnimTime(long int time, int index);  // Установка времени смены спрайтов
		void Update(int delta);
	};
}

#endif // ANIMATION_H_
