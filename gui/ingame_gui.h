#ifndef INGAME_GUI_H_INCLUDED
#define INGAME_GUI_H_INCLUDED

#include "gui.h"
#include "layout.h"
#include "tool_gui.h"

#define HGUI 100

class Entity;
class GuiTool;

class GuiIngame : public Gui
{
public:
    GuiIngame(std::vector<Entity*> *selection, Entity* &hovered);
    virtual ~GuiIngame();
    virtual void drawBefore(sf::RenderTarget &render, Vec pos, Vec dim) const;
    virtual void drawAfter(sf::RenderTarget &render, Vec pos, Vec dim) const;
    virtual void update(const PlayerController &render, Vec pos, Vec dim);

    virtual Vec getPreferredSize() const;

    bool mouseOnGui(Vec mousePos, Vec drawPos, Vec drawDim) const;

private:
    Vec m_mousePos;
    GuiTool *m_guiTool;
};
#include "../entity/entity.h"

#endif // INGAME_GUI_H_INCLUDED
