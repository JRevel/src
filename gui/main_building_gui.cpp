#include <SFML/Graphics.hpp>

#include "../graphic/util.h"
#include "main_building_gui.h"

#include "layout.h"
#include "button_gui.h"
#include "command_button.h"
#include "layout.h"

GuiMainBuilding::GuiMainBuilding(MainBuilding *building) : m_building(building)
{
    StackLayout *layout = new StackLayout(HLEFT);
    layout->addChild(new LayoutFiller);
    GuiCommandButton *button = new GuiCommandButton(Vec(50, 50), "ballIcon", 100);
    button->addLoadListener(this);
    layout->addChild(button);
    layout->addChild(new LayoutFiller);
    addChild(layout);
}

GuiMainBuilding::~GuiMainBuilding()
{

}

void GuiMainBuilding::update(const PlayerController &event, Vec pos, Vec dim)
{

}

void GuiMainBuilding::drawBefore(sf::RenderTarget &render, Vec pos, Vec dim) const
{

}

void GuiMainBuilding::actionPerformed(const PlayerController &event, Vec pos, Vec dim, Gui* target)
{

}

void GuiMainBuilding::loaded(LoadingEvent* gui)
{
    m_building->spawnBall();
}
