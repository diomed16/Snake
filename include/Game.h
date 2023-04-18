#ifndef GAME_H
#define GAME_H
#include "snake.h"

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();


private:
        snake Snake1;
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    sf::Vector2f pos;
    float m_snakeSize;
    sf::Color m_snakeColor;
    float m_snakeSpeed;

    sf::RenderWindow mWindow;
    sf::Time mTimePerFrame;

};

#endif
