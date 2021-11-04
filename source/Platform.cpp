//
// Created by inte on 11/4/21.
//

#include "Platform.h"

Platform::Platform() {

}

double Platform::getVelocityX() {return m_velocityX;}

double Platform::getVelocityY() {return m_velocityY;}

void Platform::setVelocityX(double velocityX) {m_velocityX = velocityX;}

void Platform::setVelocityY(double velocityY) {m_velocityY = velocityY;}

Static_Platform::Static_Platform() = default;

Horizontal_Platform::Horizontal_Platform()
{
    // Beweegt horizontaal dus heeft een VelocityX
    setVelocityX(10);
}

Vertical_Platform::Vertical_Platform()
{
    //Beweegt verticaal dus heeft een VelocityY
    setVelocityY(10);
}

Temporary_Platform::Temporary_Platform() = default;
