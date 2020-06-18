#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <vector>
#include<string>
#include <SFML/Graphics.hpp>
 using MessageContainer = std::vector<std::string>;
 using namespace sf;
class TextBox
{
    public:
        TextBox();
        TextBox(int l_visible, int l_charSize, int l_width, Vector2f l_screenPos);
        void Setup(int l_visible, int l_charSize, int l_width, Vector2f l_screenPos);
        void Add(std::string l_message);
        void Clear();
        void Render (RenderWindow& l_wind);
        virtual ~TextBox();

    protected:

    private:
        MessageContainer m_messages;
        int m_numVisible;
        RectangleShape m_backdrop;
        Font m_font;
        Text m_content;
};

#endif // TEXTBOX_H
