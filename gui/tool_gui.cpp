#include <SFML/Graphics.hpp>

#include "../graphic/util.h"
#include "tool_gui.h"

#include "layout.h"
#include "button_gui.h"

GuiTool::GuiTool(std::vector<Entity*> *selection, Entity*& hovered) : m_selection(selection), m_hovered(hovered), m_guiSelected(-1)
{

}

void GuiTool::drawBefore(sf::RenderTarget &render, Vec pos, Vec dim) const
{
    draw::drawRect(render, pos, dim, sf::Color::Red, 1, sf::Color::Green);

    if(m_guiSelected >= 0)
    {
        (*m_selection)[m_guiSelected]->getGui()->drawChildren(render, pos, dim);
    }
    else
    {
        int buttonDim = 20;
        int extMargin = 15;
        int inMargin = 3;
        int buttonPerRow = (dim.x-2*extMargin+inMargin)/(buttonDim+inMargin);
        for(int i=0; i<m_selection->size(); i++)
        {
            sf::Color col = sf::Color::Green;
            if(m_hovered == (*m_selection)[i])
            {
                col = sf::Color::Blue;
            }
            draw::drawRect(render, pos+Vec(extMargin+(buttonDim+inMargin)*(i%buttonPerRow), extMargin+(buttonDim+inMargin)*(i/buttonPerRow)), Vec(buttonDim, buttonDim), sf::Color::Red, 1, col);
        }
    }
}

void GuiTool::update(const PlayerController &event, Vec pos, Vec dim)
{
    int buttonDim = 20;
    int extMargin = 15;
    int inMargin = 3;
    int buttonPerRow = (dim.x-2*extMargin+inMargin)/(buttonDim+inMargin);
    int x = (event.mousePos().x-pos.x-extMargin)/(buttonDim+inMargin);
    int y = (event.mousePos().y-pos.y-extMargin)/(buttonDim+inMargin);
    int hovered = x + y*buttonPerRow;
    if(m_guiSelected >= 0)
    {
        (*m_selection)[m_guiSelected]->getGui()->updateChildren(event, pos, dim);
        if(event.pressed(ORDER) && event.mousePos().y > pos.y)
            m_guiSelected = -1;
            m_hovered = (*m_selection)[m_guiSelected];
    }
    else
    {
        if(hovered < m_selection->size() && !(x < 0 || y < 0 || x >= buttonPerRow || y >= buttonPerRow || hovered > m_selection->size() || event.mousePos().y-pos.y-extMargin < 0) && event.mousePos().x-pos.x-extMargin > 0)
        {
            m_hovered = (*m_selection)[hovered];
            if(event.pressed(SELECT))
                m_guiSelected = hovered;
        }
    }
}
