#ifndef myWindow_H
#define myWindow_H
#include "Snake.h"
#include <SFML/Graphics.hpp>
using namespace sf;


class myWindow
{
public:
    myWindow();
    myWindow(const std::string& l_title,const Vector2u& l_size);
    ~myWindow();
    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.
    void Update();
    bool IsDone();
    bool IsFullscreen();
    Vector2u GetWindowSize();
    void ToggleFullscreen();
    void Draw(Drawable& l_drawable);
    RenderWindow* GetRenderWindow();
private:
    void Setup(const std::string& l_title, const Vector2u& l_size);
    void Destroy();
    void Create();
    RenderWindow m_window;
    Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;

};

#endif // myWindow_H
