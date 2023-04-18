#include "Game.h"
#include "snake.h"

Game::Game()
: mWindow(sf::VideoMode(800, 600), "SFML Game")
, mTimePerFrame(sf::seconds(1.f / 60.f)), Snake1(1.0f,1.0f)
{

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

void Game::update(sf::Time deltaTime) {
    // TODO: добавить обновление игровой логики
}

void Game::render() {
    mWindow.clear();
    // TODO: добавить отрисовку игровых объектов
    mWindow.draw(Snake1.getHead());
   // mWindow.draw(Snake1.getBody());
    mWindow.display();
}
