#include "snake.h"

snake::snake(float size, float speed)
{
 lives = 3;
 head.setFillColor(sf::Color::Green);

 head.setPosition(100, 150);
 head.setSize(sf::Vector2f(size, size));
 snakeSegment.setSize(sf::Vector2f(size, size));
 snakeSegment.setFillColor(sf::Color::Red);
 this-> size = 1;
 this-> speed = speed;
 this->direction=Right;

     //ctor
}

bool snake::checkWallCollision()
{


}

sf::RectangleShape snake::getHead()
{
    return head;
}

std::vector <sf::RectangleShape> snake::getBody()
{
    return body;
}

void snake::update() {

    if (checkWallCollision()) {

    }

//    moveHead();

 //   moveBody();
}

void snake::addSegment()
{
    body.push_back(snakeSegment);
    body.back().setPosition(head.getPosition.x-1,head.getPosition.y+1);
}

void snake::draw()
{

}
void snake::reset()
{
   head.setPosition(100, 150);
   body.clear();
   addSegment();
   addSegment();
}

snake::~snake()
{
    //dtor
}
