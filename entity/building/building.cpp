#include <SFML/Graphics.hpp>

#include "building.h"

Building::Building(Player &player, Vec pos, int maxHealth) : Entity(player, pos, BUILDING, maxHealth)
{

}

Building::Building(const Building &model) : Entity(model)
{

}

RoundBuilding::RoundBuilding(Player &player, Vec pos, double r, int maxHealth) : Building(player, pos, maxHealth), m_r(r)
{

}

RoundBuilding::RoundBuilding(const RoundBuilding &model) : Building((Building&)model), m_r(model.m_r)
{

}

double RoundBuilding::r() const
{
    return m_r;
}

bool RoundBuilding::doesBallCollide(const Ball &ball) const
{
    return distSquared(*this, ball) < m_r*m_r;
}

bool RoundBuilding::isInside(Vec pos) const
{
    return distSquared(*this, pos) < m_r*m_r;
}

bool RoundBuilding::colRect(Vec A, Vec B) const
{
    double minX = std::min(A.x, B.x);
    double minY = std::min(A.y, B.y);
    double maxX = std::max(A.x, B.x);
    double maxY = std::max(A.y, B.y);
    return (x > minX && x < maxX && (y + r() > minY && y - r() < maxY))
            || (y > minY && y < maxY && (x + r() > minX && x - r() < maxX))
            || distSquared(getPos(), A) < r()*r()
            || distSquared(getPos(), B) < r()*r()
            || distSquared(getPos(), Vec(A.x, B.y)) < r()*r()
            || distSquared(getPos(), Vec(B.x, A.y)) < r()*r();
}
