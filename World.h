#ifndef WORLD_H
#define WORLD_H
#include "Snake.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class World
{
    public:
        World(Vector2u l_windSize);
        virtual ~World();
        int GetBlockSize();
        void RespawnApple();
        void Update(Snake& l_player);
        void Render(RenderWindow &l_window);


    protected:

    private:
        Vector2u m_windowSize;
        Vector2i m_item;
        int m_blockSize;
        CircleShape m_appleShape;
        RectangleShape m_bounds[4];
};

#endif // WORLD_H
