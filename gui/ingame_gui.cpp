#include <SFML/Graphics.hpp>

#include "../graphic/util.h"
#include "ingame_gui.h"
#include "layout.h"
#include "tool_gui.h"
#include "button_gui.h"

GuiIngame::GuiIngame(std::vector<Entity*> *selection, Entity* &hovered) : m_guiTool(new GuiTool(selection, hovered))
{

}

GuiIngame::~GuiIngame()
{
    delete m_guiTool;
}

void GuiIngame::drawBefore(sf::RenderTarget &render, Vec pos, Vec dim) const
{
    //draw::drawRect(render, pos+Vec(0, dim.y-150), Vec(dim.x, 150), sf::Color::Red, 1, sf::Color::Green);

}

void GuiIngame::drawAfter(sf::RenderTarget &render, Vec pos, Vec dim) const
{
    m_guiTool->drawChildren(render, pos+Vec(0, dim.y-HGUI), Vec(dim.x, HGUI));
    draw::drawRect(render, pos+m_mousePos, Vec(3, 3), sf::Color::Red, 1, sf::Color::Green);
}

void GuiIngame::update(const PlayerController &event, Vec pos, Vec dim)
{
    m_mousePos = event.mousePos();
    m_guiTool->updateChildren(event, pos+Vec(0, dim.y-HGUI), Vec(dim.x, HGUI));
}

Vec GuiIngame::getPreferredSize() const
{
    return Vec(0, 0);
}

bool GuiIngame::mouseOnGui(Vec mousePos, Vec drawPos, Vec drawDim) const
{
    return mousePos.y > drawPos.y+drawDim.y-HGUI;
}
