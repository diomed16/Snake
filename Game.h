#ifndef GAME_H
#define GAME_H

#include "World.h"
#include "Snake.h"
#include "myWindow.h"
#include "TextBox.h"
#include <SFML/Graphics.hpp>

#include <string>

class Game
{
    public:
        Game();
        virtual ~Game();

        void HandleInput();
        void Update();
        void Render();

        Time GetElapsed();
        void RestartClock();
        myWindow* GetWindow();

    protected:

    private:

        myWindow m_window;



        Snake m_snake;
        World m_world;

        TextBox m_textbox;
        Clock m_clock;
        float m_elapsed;


};

#endif // GAME_H
