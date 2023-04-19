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
    void reset();
    void draw(sf::RenderWindow&);
    enum Direction { None, Up, Down, Left, Right };
    void setDirection(Direction);

    protected:

    private:
      int lives;
      int size;
      int speed;
      sf::RectangleShape snakeSegment;
      sf::RectangleShape head;
      std::vector <sf::RectangleShape>body;

      void moveBody();
      void moveHead();

      Direction direction;
      bool checkWallCollision();
      bool checkFoodCollision(sf::RectangleShape food);
};

#endif // SNAKE_H
