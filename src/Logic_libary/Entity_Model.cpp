#include "Entity_Model.h"

namespace logic {

    Entity_Model::Entity_Model() {

    }

    void Entity_Model::setX(double x) {m_x = x;}

    void Entity_Model::setY(double y) {m_y = y;}

    void Entity_Model::setVelocityX(double velocityX) {m_velocityX = velocityX;}

    void Entity_Model::setVelocityY(double velocityY) {m_velocityY = velocityY;}

    void Entity_Model::setLenght(double lenght) {m_lenght = lenght;}

    void Entity_Model::setWidth(double width) {m_width = width;}

    double Entity_Model::getX() const {return m_x;}

    double Entity_Model::getY() const {return m_y;}

    double Entity_Model::getVelocityX() const {return m_velocityX;}

    double Entity_Model::getVelocityY() const {return m_velocityY;}

    double Entity_Model::getLenght() const {return m_lenght;}

    double Entity_Model::getWidth() const {return m_width;}

    void Entity_Model::moveRight() {}

    void Entity_Model::moveLeft() {}
}


