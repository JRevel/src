#ifndef LISTENER_H_INCLUDED
#define LISTENER_H_INCLUDED

#include "gui.h"

class Gui;

class Listener
{
public:
    virtual void actionPerformed(const PlayerController &controller, Vec pos, Vec dim, Gui* gui) = 0;
};

class LoadingEvent;

class LoadListener
{
public:
    virtual void loaded(LoadingEvent *gui) = 0;
};

class LoadingEvent
{
public:
    void addLoadListener(LoadListener *listener);
    void triggerEvent();
private:
    std::vector<LoadListener*> m_listeners;
};

#endif // LISTENER_H_INCLUDED
