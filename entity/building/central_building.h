#ifndef CENTRAL_BUILDING_H_INCLUDED
#define CENTRAL_BUILDING_H_INCLUDED

#include "building.h"

class MainBuilding : public RoundBuilding
{
public:
    MainBuilding(Player &player, Vec pos);
    ~MainBuilding();

    virtual void handleInteraction(Entity *entity);
    virtual void receiveOrder(const PlayerController &event);
    virtual void draw(sf::RenderTarget &render);
    virtual void drawSelected(sf::RenderTarget &render);
    virtual void drawHovered(sf::RenderTarget &render);
    virtual void drawForeground(sf::RenderTarget &render, Vec mousePos);
    virtual void update();

    void spawnBall();

private:
    Vec m_target;
    sf::Sprite m_sprite, m_hoveredSprite, m_selectedSprite, m_targetSprite;
};

#endif // CENTRAL_BUILDING_H_INCLUDED
