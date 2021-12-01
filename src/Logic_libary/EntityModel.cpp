#include "EntityModel.h"

namespace logic {

    EntityModel::EntityModel() = default;

    void EntityModel::setX(float x) {m_x = x;}

    void EntityModel::setY(float y) {m_y = y;}

    void EntityModel::setVelocityX(float velocityX) {m_velocityX = velocityX;}

    void EntityModel::setVelocityY(float velocityY) {m_velocityY = velocityY;}

    void EntityModel::setHeight(float height) {m_height = height;}

    void EntityModel::setWidth(float width) {m_width = width;}

    float EntityModel::getX() const {return m_x;}

    float EntityModel::getY() const {return m_y;}

    float EntityModel::getVelocityX() const {return m_velocityX;}

    float EntityModel::getVelocityY() const {return m_velocityY;}

    float EntityModel::getHeight() const {return m_height;}

    float EntityModel::getWidth() const {return m_width;}

    void EntityModel::moveRight() {}

    void EntityModel::moveLeft() {}

}


