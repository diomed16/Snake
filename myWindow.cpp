#include "myWindow.h"

myWindow::myWindow()
{
Setup("Window", Vector2u(800,600));
}
myWindow::myWindow(const std::string& l_title, const Vector2u& l_size)
{
Setup(l_title, l_size);
}



void myWindow::Setup(const std::string& l_title, const Vector2u& l_size)
{
    m_windowTitle=l_title;
    m_windowSize=l_size;
    m_isFullscreen=false;
    m_isDone=false;
    Create();
}

void myWindow::Create()
{
    auto style = (m_isFullscreen ? Style::Fullscreen : Style::Default);
    m_window.create({m_windowSize.x,m_windowSize.y},m_windowTitle,style);

}

void myWindow::Destroy()
{
    m_window.close();
}

void myWindow::Update()
{
    Event event;
    while(m_window.pollEvent(event))
    {
        if (event.type==Event::Closed)
        {
            m_isDone=true;
        }
        else if (event.type==Event::KeyPressed && event.key.code==Keyboard::F5)
        {
            ToggleFullscreen();
        }
    }
}

void myWindow::ToggleFullscreen()
{
    m_isFullscreen=!m_isFullscreen;
    Destroy();
    Create();
}

void myWindow::BeginDraw()
{
    m_window.clear(Color::Black);
}

void myWindow::EndDraw()
{
    m_window.display();
}

bool myWindow::IsDone()
{
    return m_isDone;
}

RenderWindow* myWindow::GetRenderWindow()
{
    return &m_window;
}

Vector2u myWindow::GetWindowSize()
{
    return m_windowSize;
}

void myWindow::Draw(Drawable& l_drawable)
{
    m_window.draw(l_drawable);
}

myWindow::~myWindow()
{
   Destroy();
}
