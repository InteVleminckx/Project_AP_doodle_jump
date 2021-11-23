#include "Entity_Model.h"

namespace logic {

    Entity_Model::Entity_Model() {

    }

    void Entity_Model::setX(float x) {m_x = x;}

    void Entity_Model::setY(float y) {m_y = y;}

    void Entity_Model::setVelocityX(float velocityX) {m_velocityX = velocityX;}

    void Entity_Model::setVelocityY(float velocityY) {m_velocityY = velocityY;}

    void Entity_Model::setLenght(double lenght) {m_lenght = lenght;}

    void Entity_Model::setWidth(double width) {m_width = width;}

    float Entity_Model::getX() const {return m_x;}

    float Entity_Model::getY() const {return m_y;}

    float Entity_Model::getVelocityX() const {return m_velocityX;}

    float Entity_Model::getVelocityY() const {return m_velocityY;}

    double Entity_Model::getLenght() const {return m_lenght;}

    double Entity_Model::getWidth() const {return m_width;}

    void Entity_Model::moveRight() {}

    void Entity_Model::moveLeft() {}
}


