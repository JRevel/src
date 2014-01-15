#include <SFML/Graphics.hpp>

#include "central_building.h"
#include "../../world/world.h"
#include "../../graphic/image_manager.h"
#include "../../gui/main_building_gui.h"
#include "../../graphic/util.h"

MainBuilding::MainBuilding(Player &player, Vec pos) : RoundBuilding(player, pos, 100, 10000)
{
    sf::Texture *texture = ImageManager::instance.getTexture("mainBuilding");
    m_sprite.setTexture(*texture);
    m_sprite.setPosition(x-r(), y-r());
    m_sprite.setScale(sf::Vector2f(2*r()/texture->getSize().x, 2*r()/texture->getSize().y));
    m_sprite.setColor(player.getBaseColor());
    m_hoveredSprite.setTexture(*texture);
    m_hoveredSprite.setPosition(x-r(), y-r());
    m_hoveredSprite.setScale(sf::Vector2f(2*r()/texture->getSize().x, 2*r()/texture->getSize().y));
    m_hoveredSprite.setColor(player.getBaseColor());
    sf::Texture *selectedTexture = ImageManager::instance.getTexture("mainBuildingSelected");
    m_selectedSprite.setTexture(*selectedTexture);
    m_selectedSprite.setPosition(x-m_selectedSprite.getLocalBounds().width, y-m_selectedSprite.getLocalBounds().height);
    m_selectedSprite.setScale(sf::Vector2f(2*r()/texture->getSize().x, 2*r()/texture->getSize().y));
    m_selectedSprite.setColor(player.getSelectedColor());
    m_gui = new GuiMainBuilding(this);;
    sf::Texture *crossTexture = ImageManager::instance.getTexture("cross");
    m_targetSprite.setTexture(*crossTexture);
    m_targetSprite.setPosition(x-m_targetSprite.getLocalBounds().width, y-m_targetSprite.getLocalBounds().height);
    m_targetSprite.setColor(player.getSelectedColor());
}


MainBuilding::~MainBuilding()
{

}

void MainBuilding::handleInteraction(Entity *other)
{
    if(other->getType() == BALL)
    {
        Ball* ball = (Ball*)other;
        if(dist(*ball, *this) < (r()+ball->r()) && (*ball-*this)*ball->getSpeed() <= 0)
        {
            if(&ball->getPlayer() != &getPlayer())
                damage((ball->getSpeed().proj(*ball-getPos())).normSquared()*ball->m());
            ball->bounce(*this-*ball);
            ball->setPos(*this+(*ball-*this).getVectWithNorm(r()+ball->r()));
        }
    }
}

void MainBuilding::receiveOrder(const PlayerController &event)
{
    if(event.pressed(ORDER))
        m_target = m_player.screenToWorld(event.mousePos());
}

void MainBuilding::update()
{

}

void MainBuilding::draw(sf::RenderTarget &render)
{
    m_sprite.setPosition(x-m_sprite.getGlobalBounds().width/2, y-m_sprite.getGlobalBounds().height/2);
    render.draw(m_sprite);
}

void MainBuilding::drawSelected(sf::RenderTarget &render)
{
    m_selectedSprite.setPosition(x-m_selectedSprite.getGlobalBounds().width/2, y-m_selectedSprite.getGlobalBounds().height/2);
    render.draw(m_selectedSprite);
    m_targetSprite.setPosition(m_target.x-m_targetSprite.getGlobalBounds().width/2, m_target.y-m_targetSprite.getGlobalBounds().height/2);
    render.draw(m_targetSprite);
}

void MainBuilding::drawHovered(sf::RenderTarget &render)
{
    m_hoveredSprite.setPosition(x-r(), y-r());
    render.draw(m_hoveredSprite);
}

void MainBuilding::drawForeground(sf::RenderTarget &render, Vec mousePos)
{
    if(/*distSquared(getPos(), mousePos) < 10000 ||*/ getLastHitTime() < 150)
        drawHealthBar(render, getPos()-Vec(r()*0.8, r()/8), Vec(r()*2*0.8, r()/4), std::max(1-distSquared(getPos(), mousePos)/10000, getLastHitTime() < 150 ? 1-getLastHitTime()/150.0:0));
}

void MainBuilding::spawnBall()
{
    Ball *ball = new Ball(m_player, getPos()+(m_target-getPos()).getVectWithNorm(1), 15, 1, Vec(1, 0), 100);

    m_world->addEntity(ball);
    m_world->addMovement(new MovementHandler(ball, m_target));
}
