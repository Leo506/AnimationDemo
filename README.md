# AnimationDemo
Демо анимации на C++ (SFML)  
Этот репозиторий был создан для небольшой демки по созданию спрайтовой анимации в C++ с использованием SFML,
чтобы разобраться с устройством спрайтовых анимаций в играх  
## Результат  
![alt result](https://github.com/Leo506/AnimationDemo/blob/main/Assets/ResultVideo/result.gif)
## Установка на Linux
1. Установить библиотеку SFML([офф. сайт](https://www.sfml-dev.org/)) `sudo apt-get install libsfml-dev`
2. Скачать библиотеку ImGui ([ссылка на репозиторий](https://github.com/ocornut/imgui))
3. Склонировать репозиторий
4. Скомпилировать проект с помощью команды:  
`g++ *.cpp /path/to/ImGui/*.cpp -I /path/to/ImGui/ -I /path/to/ImGui/backends/ -lsfml-graphics -lsfml-system -lsfml-window -lglut -lGL`
4. Запустить демку `./a.out`
