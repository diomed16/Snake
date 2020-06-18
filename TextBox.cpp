#include "TextBox.h"

TextBox::TextBox()
{
   Setup(5,9,200,Vector2f(0,0));
}
TextBox::TextBox(int l_visible, int l_charSize, int l_width, Vector2f l_screenPos)
{
    Setup(l_visible, l_charSize, l_width, l_screenPos);
}

TextBox::~TextBox()
{
    Clear();
}

void TextBox::Setup(int l_visible, int l_charSize, int l_width, Vector2f l_screenPos)
{
    m_numVisible = l_visible;
    Vector2f l_offset(2.0f, 2.0f);
    m_font.loadFromFile("arial.ttf");
    m_content.setFont(m_font);
    m_content.setString(L"");
    m_content.setCharacterSize(l_charSize);
    m_content.setColor(Color::White);
    m_content.setPosition(l_screenPos+l_offset);
    m_backdrop.setSize(Vector2f(l_width,(l_visible*(l_charSize*1.2f))));
    m_backdrop.setFillColor(Color(90,90,90,90));
    m_backdrop.setPosition(l_screenPos);
}

void TextBox::Add(std::string l_message)
{
    m_messages.push_back(l_message);
    if (m_messages.size()<6)
    {
        return;
    }
    m_messages.erase(m_messages.begin());
}

void TextBox::Clear()
{
    m_messages.clear();
}

void TextBox::Render(RenderWindow& l_wind)
{
    std::string l_content;
    for (auto &itr : m_messages)
    {
        l_content.append(itr+"\n");
    }
    if (l_content!="")
    {
        m_content.setString(l_content);
        l_wind.draw(m_backdrop);
        l_wind.draw(m_content);
    }
}


