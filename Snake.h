#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include "TextBox.h"
#include <SFML/Audio.hpp>
using namespace sf;
struct SnakeSegment
{
    SnakeSegment(int x, int y):position(x,y){}
    Vector2i position;
};
using SnakeContainer = std :: deque <SnakeSegment>;

enum class Direction {None, Up, Down,Left, Right};


class Snake
{
    public:
        Snake(int l_blockSize, TextBox* l_log);
        virtual ~Snake();
// Helper methods
        void SetDirection(Direction l_dir);
        Direction GetDirection();
        Direction GetPhysicalDirection();
        int GetSpeed();
        int GetScore();
        int GetLives();

        void IncreaseScore();
        bool HasLost();
        void Lose();
        void ToggleLost();

        void Extend(); //Рост змеи
        void Reset(); //reset to start position
        void Move();
        void Tick(); //Update method
        void Cut(int l_segments); //отрезание змеи
        void Render(sf::RenderWindow &l_window);
        Vector2i GetPosition();

    protected:

    private:
        Sound sound;
        TextBox* m_log;
        void CheckCollision();
        int m_size; //размер изображения
        Direction m_dir; //current direction
        SnakeContainer m_snakeBody;
        int m_speed; //Скорость змеи
        int m_score;
        int m_lives;
        bool m_lost;
        RectangleShape m_bodyRect; // body

};



#endif // SNAKE_H
