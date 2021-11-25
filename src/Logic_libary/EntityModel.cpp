#include "EntityModel.h"

namespace logic {

    EntityModel::EntityModel() {

    }

    void EntityModel::setX(float x) {m_x = x;}

    void EntityModel::setY(float y) {m_y = y;}

    void EntityModel::setVelocityX(float velocityX) {m_velocityX = velocityX;}

    void EntityModel::setVelocityY(float velocityY) {m_velocityY = velocityY;}

    void EntityModel::setLenght(double lenght) {m_lenght = lenght;}

    void EntityModel::setWidth(double width) {m_width = width;}

    float EntityModel::getX() const {return m_x;}

    float EntityModel::getY() const {return m_y;}

    float EntityModel::getVelocityX() const {return m_velocityX;}

    float EntityModel::getVelocityY() const {return m_velocityY;}

    double EntityModel::getLenght() const {return m_lenght;}

    double EntityModel::getWidth() const {return m_width;}

    void EntityModel::moveRight() {}

    void EntityModel::moveLeft() {}
}


