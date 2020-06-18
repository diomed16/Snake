#include "Game.h"
#include<string>
#include <SFML/Audio.hpp>
Game::Game() : m_window("Snake", Vector2u(800, 600)),
m_snake(m_world.GetBlockSize(), &m_textbox),m_world(Vector2u(800,600))
{
    m_clock.restart();
	srand(time(nullptr));
    m_elapsed = 0.0f;
    m_textbox.Setup(5,14,350,Vector2f(225,0));
    m_textbox.Add("Ну чо, жми стрелочки");


}

Time Game::GetElapsed(){ return m_clock.getElapsedTime(); }
void Game::RestartClock(){ m_elapsed += m_clock.restart().asSeconds(); }
myWindow* Game::GetWindow(){ return &m_window; }

void Game::Update()
{
    m_window.Update();
    float timeStep = 1.0f/m_snake.GetSpeed();
    if (m_elapsed>=timeStep)
    {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed-=timeStep;
        if (m_snake.HasLost())
        {
            m_snake.Reset();

        }
    }
}

void Game::Render()
{
    m_window.BeginDraw();
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_textbox.Render(*m_window.GetRenderWindow());

    m_window.EndDraw();
}

void Game::HandleInput()
{
    if (Keyboard::isKeyPressed(Keyboard::Up) && m_snake.GetPhysicalDirection()!=Direction::Down)
    {
        m_snake.SetDirection(Direction::Up);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down) && m_snake.GetPhysicalDirection()!=Direction::Up)
    {
        m_snake.SetDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetPhysicalDirection() != Direction::Right)
    {
        m_snake.SetDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetPhysicalDirection() != Direction::Left)
    {
        m_snake.SetDirection(Direction::Right);
    }
}




Game::~Game()
{
    //dtor
}
