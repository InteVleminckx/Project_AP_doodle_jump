#include "EntityModel.h"

namespace logic {

EntityModel::EntityModel() = default;

void EntityModel::setX(float x) { m_x = x; }

void EntityModel::setY(float y) { m_y = y; }

void EntityModel::setXprev(float x) { m_xPrev = x; }

void EntityModel::setYprev(float y) { m_yPrev = y; }

void EntityModel::setVelocityX(float velocityX) { m_velocityX = velocityX; }

void EntityModel::setVelocityY(float velocityY) { m_velocityY = velocityY; }

void EntityModel::setHeight(float height) { m_height = height; }

void EntityModel::setWidth(float width) { m_width = width; }

void EntityModel::setGravity(float gravity) { m_gravity = gravity; }

float EntityModel::getX() const { return m_x; }

float EntityModel::getY() const { return m_y; }

float EntityModel::getXprev() const { return m_xPrev; }

float EntityModel::getYprev() const { return m_yPrev; }

int EntityModel::getProjectedX() const { return m_projectedX; }

int EntityModel::getProjectedY() const { return m_projectedY; }

float EntityModel::getVelocityX() const { return m_velocityX; }

float EntityModel::getVelocityY() const { return m_velocityY; }

float EntityModel::getHeight() const { return m_height; }

float EntityModel::getWidth() const { return m_width; }

float EntityModel::getGravity() const { return m_gravity; }

void EntityModel::Notify()
{
        for (auto& ob : getObservers()) {
                ControllingPointers::control(ob, "EntityModel", "Notify()");
                projectPointsToPixels();
                ob->update();
        }
}

void EntityModel::projectPointsToPixels()
{
        projectedPixels pixels = logic::Camera::Instance()->projectToPixel(getX(), getY());
        m_projectedX = pixels.x;
        m_projectedY = pixels.y;
}

EntityModel::~EntityModel() = default;

} // namespace logic
