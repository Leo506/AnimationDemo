#ifndef ANIMATOR_H_INCLUDED
#define ANIMATOR_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "animation.h"

namespace animation
{
	class Animator
	{
	private:
		sf::RenderWindow *m_window;  // Игровое окно, к которому будет привязан UI инструмента
		AnimationClip *m_clip;       // Анимация, над которой ведётся работа
		float m_speed;               // Скорость анимации
		std::string m_path;          // Путь к файлу со спрайтами
		sf::IntRect m_rect;          // Размеры и координаты первого спрайта
		int m_countOfSprites;        // Кол-во спрайтов в анимации
		bool m_animationIsSet;       // Установлена ли анимация?

	public:
		// Конструктор аниматора
		// window - игровое окно, к которому будет привязан UI инструмента
		// clip - анимация, над которой ведётся работа
		Animator(sf::RenderWindow* const window, AnimationClip *clip);

		Animator(sf::RenderWindow* const window);

		// ImGui работает с выделением памяти, поэтому нужен явный декструктор
		~Animator();

		// Обработчик событий
		void ProcessEvent(const sf::Event &event);

		// Рендер UI
		void Render();

		// Установка новой анимации
		void SetAnimClip(AnimationClip *clip);

		// Обновление аниматора
		void Update(const sf::Time& deltaTime);

		const bool IsSet() const { return m_animationIsSet; }

	};
}

#endif // ANIMATOR_H_INCLUDED
