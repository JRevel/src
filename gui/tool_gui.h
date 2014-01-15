#ifndef TOOL_GUI_H_INCLUDED
#define TOOL_GUI_H_INCLUDED

#include "gui.h"
#include "../entity/entity.h"

class GuiTool : public Gui
{
public:
    GuiTool(std::vector<Entity*> *selection, Entity* &hovered);
    virtual void drawBefore(sf::RenderTarget &render, Vec pos, Vec dim) const;
    virtual void update(const PlayerController &render, Vec pos, Vec dim);

private:
    std::vector<Entity*> *m_selection;
    Entity*& m_hovered;
    int m_guiSelected;
};

#endif // TOOL_GUI_H_INCLUDED
