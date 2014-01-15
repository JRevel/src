#ifndef MAIN_BUILDING_GUI_H_INCLUDED
#define MAIN_BUILDING_GUI_H_INCLUDED

#include "gui.h"
#include "../entity/building/central_building.h"

class GuiMainBuilding : public Gui, public LoadListener
{
public:
    GuiMainBuilding(MainBuilding *building);
    virtual ~GuiMainBuilding();

    virtual void update(const PlayerController &event, Vec pos, Vec dim);
    virtual void drawBefore(sf::RenderTarget &render, Vec pos, Vec dim) const;
    virtual void actionPerformed(const PlayerController &event, Vec pos, Vec dim, Gui* target);
    virtual void loaded(LoadingEvent *event);

private:
    MainBuilding *m_building;
};

#endif // MAIN_BUILDING_GUI_H_INCLUDED
