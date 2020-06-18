
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"
#include "Game.h"
using namespace sf;
int main()
{
    setlocale(LC_ALL,"Rus");
    Game game;
    Music music;//создаем объект музыки
    music.openFromFile("POL-around-the-world-short.wav");//загружаем файл
    music.setVolume(20);
    music.play();

    while(!game.GetWindow()->IsDone()){
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();


    }

	return 0;
}
