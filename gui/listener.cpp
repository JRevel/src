#include "listener.h"

void LoadingEvent::addLoadListener(LoadListener *listener)
{
    m_listeners.push_back(listener);
}

void LoadingEvent::triggerEvent()
{
    for(int i=0; i<m_listeners.size(); i++)
        m_listeners[i]->loaded(this);
}
