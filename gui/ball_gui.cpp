#include <SFML/Graphics.hpp>
#include <sstream>

#include "../graphic/util.h"
#include "ball_gui.h"
#include "button_gui.h"

GuiBall::GuiBall(Ball *ball) : Gui(), m_ball(ball)
{
    StackLayout *layout = new StackLayout(HLEFT);
    layout->addChild(new LayoutFiller);
    GuiButton *button = new GuiButton(0, Vec(50, 50), sf::Color::Blue, sf::Color(100, 100, 255));
    button->addListener(this);
    layout->addChild(button);
    layout->addChild(new LayoutFiller);
    addChild(layout);
}

void GuiBall::drawAfter(sf::RenderTarget &render, Vec pos, Vec dim) const
{

}

void GuiBall::actionPerformed(const PlayerController &controller, Vec pos, Vec dim, Gui* gui)
{

}
