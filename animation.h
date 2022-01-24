#ifndef ANIMATION_H_
#define ANIMATION_H_
#include <iostream>
#include <SFML/Graphics.hpp>

namespace animation
{
	class AnimationClip
	{
	private:
		sf::Texture* m_sprite[6];                       // Спрайты анимации
		sf::Sprite* m_currentSprite;                   // Текущий спрайт
		long int m_lostTime;                           // Прошедшее время
		int m_current;                                 // Текущий спрайт
		long int m_times[6]={83, 166, 249, 332, 410, 498};        // Время смены спрайтов

	public:
		AnimationClip(std::string path, sf::Sprite* sprite, sf::IntRect& rect);
		~AnimationClip();
		void Update(int delta);
	};
}

#endif // ANIMATION_H_
