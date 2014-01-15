#include <SFML/Graphics.hpp>
#include <sstream>

#include "../graphic/util.h"
#include "command_button.h"
#include "../graphic/image_manager.h"

GuiCommandButton::GuiCommandButton(Vec dim, std::string text_label, int loadTime) : m_dim(dim), m_loadTime(loadTime), m_loadProgress(0)
{
    sf::Texture *texture = ImageManager::instance.getTexture(text_label);
    m_textDim = Vec(texture->getSize().x, texture->getSize().y);
    m_sprite.setTexture(*texture);
    addListener(this);
}

GuiCommandButton::~GuiCommandButton()
{

}

Vec GuiCommandButton::getPreferredSize() const
{
    return m_dim;
}

void GuiCommandButton::update(const PlayerController &event, Vec pos, Vec dim)
{
    m_sprite.setPosition(pos.x, pos.y);
    m_sprite.setScale(m_textDim.x/dim.x, m_textDim.y/dim.y);
    if(m_commands > 0)
        m_loadProgress++;
    if(m_loadProgress > m_loadTime)
    {
        m_loadProgress = 0;
        m_commands--;
        triggerEvent();
    }
}

void GuiCommandButton::drawBefore(sf::RenderTarget &render, Vec pos, Vec dim) const
{
    draw::drawRect(render, pos, dim, sf::Color::White, 1, sf::Color::Black);
    render.draw(m_sprite);
    if(m_commands > 0)
    {
        draw::drawRect(render, pos+Vec(0, dim.y-10), Vec(dim.x, 10), sf::Color::Black, 1, sf::Color::Red);
        draw::drawRect(render, pos+Vec(0, dim.y-10), Vec(dim.x*m_loadProgress/m_loadTime, 10), sf::Color::Black, 1, sf::Color::Green);
    }
    if(m_commands > 1)
    {
        draw::drawRect(render, pos, Vec(20, 20), sf::Color::White, 1, sf::Color::Black);
        draw::drawText(render, pos+Vec(5, 0), draw::to_string(m_commands), 15, sf::Color::White);
    }
}

void GuiCommandButton::actionPerformed(const PlayerController &event, Vec pos, Vec dim, Gui* gui)
{
    if(event.pressed(0))
        m_commands++;
}
