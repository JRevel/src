#ifndef BALL_GUI_H_INCLUDED
#define BALL_GUI_H_INCLUDED

#include "gui.h"
#include "../entity/ball.h"

class GuiBall : public Gui, public Listener
{
public:
    GuiBall(Ball* ball);
    virtual void drawAfter(sf::RenderTarget &render, Vec pos, Vec dim) const;
    virtual void actionPerformed(const PlayerController &controller, Vec pos, Vec dim, Gui* gui);

private:
    Ball *m_ball;
};

#endif // BALL_GUI_H_INCLUDED
