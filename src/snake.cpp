#include "snake.h"

snake::snake(float size, float speed)
{
    direction = Right;
 lives = 3;
 head.setFillColor(sf::Color::Green);
this-> size = 10;
 head.setPosition(100, 150);
 head.setSize(sf::Vector2f(this->size, this->size));
 snakeSegment.setSize(sf::Vector2f(this->size, this->size));
 snakeSegment.setFillColor(sf::Color::Yellow);
 this-> size = 10;
 this-> speed = speed;
 this->direction=Right;

     //ctor
}

bool snake::checkWallCollision()
{


}
void snake::moveHead()
{
    sf::Vector2f position = head.getPosition();
    switch (direction) {
    case Up:
        position.y -= speed;
        break;
    case Down:
        position.y += speed;
        break;
    case Left:
        position.x -= speed;
        break;
    case Right:
        position.x += speed;
        break;
}

// Установить новую позицию головы змейки
head.setPosition(position);
}

void snake::moveBody()
{
    sf::Vector2f lastPosition = head.getPosition();
for (int i = body.size() - 1; i >= 0; i--) {
// Сохранить текущую позицию сегмента
sf::Vector2f currentPosition = body[i].getPosition();
body[i].setPosition(lastPosition);

    // Сохранить позицию текущего сегмента для следующего сегмента
    lastPosition = currentPosition;
}
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



    moveHead();

 moveBody();
}

void snake::setDirection(Direction dir)
{
    direction = dir;
}

void snake::addSegment()
{
    if (!body.empty())
    {

    sf::Vector2f lastPos = body.back().getPosition();
    body.push_back(snakeSegment);
        body.back().setPosition(lastPos.x,lastPos.y+size);
    }
    else
    {
        body.push_back(snakeSegment);
        body.back().setPosition(head.getPosition().x,head.getPosition().y+size);
    }
}

void snake::draw(sf::RenderWindow& window)
{
    window.draw(this->head);
    if(!body.empty())
    {
       for (auto it = this->body.begin(); it != this->body.end(); ++it) {
         window.draw(*it);
    }
    }
}
void snake::reset()
{
   head.setPosition(100, 150);
   body.clear();
   addSegment();
   addSegment();
    addSegment();
   addSegment();
    addSegment();
   addSegment();
}

snake::~snake()
{
    //dtor
}
