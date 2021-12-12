#include "EntityModel.h"


namespace logic {

    EntityModel::EntityModel() = default;

    void EntityModel::setX(float x) {m_x = x;}

    void EntityModel::setY(float y) {m_y = y;}

    void EntityModel::setVelocityX(float velocityX) {m_velocityX = velocityX;}

    void EntityModel::setVelocityY(float velocityY) {m_velocityY = velocityY;}

    void EntityModel::setHeight(float height) {m_height = height;}

    void EntityModel::setWidth(float width) {m_width = width;}

    float EntityModel::getX()  {return m_x;}

    float EntityModel::getY()  {return m_y;}

    float EntityModel::getVelocityX()  {return m_velocityX;}

    float EntityModel::getVelocityY()  {return m_velocityY;}

    float EntityModel::getHeight()  {return m_height;}

    float EntityModel::getWidth() {return m_width;}

    void EntityModel::moveRight() {}

    void EntityModel::moveLeft() {}

    void EntityModel::setXprev(float x) {m_xPrev = x;}

    void EntityModel::setYprev(float y) {m_yPrev = y;}

    float EntityModel::getXprev() {return m_xPrev;}

    float EntityModel::getYprev() {return m_yPrev;}

    void EntityModel::gravity() {}

    void EntityModel::jump() {}

}


