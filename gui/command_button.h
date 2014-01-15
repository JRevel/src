#ifndef COMMAND_BUTTON_H_INCLUDED
#define COMMAND_BUTTON_H_INCLUDED

#include "gui.h"
#include "listener.h"
#include "../entity/building/central_building.h"

class GuiCommandButton : public Gui, public Listener, public LoadingEvent
{
public:
    GuiCommandButton(Vec dim, std::string text_label, int loadTime);
    virtual ~GuiCommandButton();

    void drawBefore(sf::RenderTarget &render, Vec pos, Vec dim) const;
    void update(const PlayerController &event, Vec pos, Vec dim);
    virtual Vec getPreferredSize() const;
    virtual void actionPerformed(const PlayerController &event, Vec pos, Vec dim, Gui *gui);

private:
    sf::Sprite m_sprite;
    int m_loadTime, m_loadProgress;
    Vec m_dim;
    Vec m_textDim;
    int m_commands;
};

#endif // COMMAND_BUTTON_H_INCLUDED
