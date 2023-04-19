#include "Game.h"
#include "snake.h"

Game::Game()
: mWindow(sf::VideoMode(800, 600), "SFML Game")
, mTimePerFrame(sf::seconds(1.f / 60.f)), Snake1(1.0f,1.0f)
{

 Snake1.reset();
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen()) {
        processEvents();

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > mTimePerFrame) {
            timeSinceLastUpdate -= mTimePerFrame;
            processEvents();
            update(mTimePerFrame);
        }

        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}



void Game::handleInput()
{
    sf::Event event;
    while (mWindow.pollEvent(event)) {  // проверяем все события в очереди
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();  // закрываем окно, если была нажата кнопка "закрыть"
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Left:
                        Snake1.setDirection(snake::Left);  // устанавливаем направление змеи
                        break;
                    case sf::Keyboard::Right:
                        Snake1.setDirection(snake::Right);
                        break;
                    case sf::Keyboard::Up:
                        Snake1.setDirection(snake::Up);
                        break;
                    case sf::Keyboard::Down:
                        Snake1.setDirection(snake::Down);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    // TODO: добавить обновление игровой логики
   //Snake1.update();

}

void Game::render() {
    mWindow.clear();
    // TODO: добавить отрисовку игровых объектов
   // mWindow.draw(Snake1.getHead());

   Snake1.draw(mWindow);
;
    mWindow.display();
}
