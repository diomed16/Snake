#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <SFML/Graphics.hpp>

class snake
{
    public:
        snake(float size, float speed);
        virtual ~snake();

    int getLives();
    void setLives();
    sf::RectangleShape getHead();
    std::vector <sf::RectangleShape> getBody();
    void update();
    void addSegment();

    protected:

    private:
      int lives;
      int size;
      int speed;
      sf::RectangleShape snakeSegment;
      sf::RectangleShape head;
      std::vector <sf::RectangleShape>body;
      enum Direction { Up, Down, Left, Right };
      void moveBody();
      void moveHead();
      void draw();
      void reset();
      Direction direction;
      bool checkWallCollision();
      bool checkFoodCollision(sf::RectangleShape food);
};

#endif // SNAKE_H
