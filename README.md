# AnimationDemo
Демо анимации на C++ (SFML)  
Этот репозиторий был создан для небольшой демки по созданию спрайтовой анимации в C++ с использованием SFML,
чтобы разобраться с устройством спрайтовых анимаций в играх  
## Результат  
![alt result](https://github.com/Leo506/AnimationDemo/blob/main/Assets/ResultVideo/result.gif)
## Установка на Linux
1. Установить библиотеку SFML([офф. сайт](https://www.sfml-dev.org/)) `sudo apt-get install libsfml-dev`
2. Склонировать репозиторий
3. Скомпилировать проект с помощью команд:  
`g++ -c *.cpp`  
`g++ *.o -o AnimDemo -lsfml-graphics -lsfml-window -lsfml-system`
4. Запустить демку `./AnimDemo`
