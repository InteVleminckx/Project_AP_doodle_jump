//
// Created by inte on 11/4/21.
//

#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include <iostream>
#include "Entity.h"

using namespace std;

class Platform : public Entity {
    double m_velocityX{};
    double m_velocityY{};

public:

    Platform();

    /**
     * Geeft de velocity in de x richting terug
     * @return: double, m_velocityX
     */
    double getVelocityX();

    /**
     * Geeft de velocity in de y richting terug
     * @return: double, m_velocityY
     */
    double getVelocityY();

    /**
     * Kent een opgeven waarde toe aan de velocity in de x richting
     * @param velocityX: double, de toegekende waarde
     */
    void setVelocityX(double velocityX);

    /**
     * Kent een opgeven waarde toe aan de velocity in de y richting
     * @param velocityX: double, de toegekende waarde
     */
    void setVelocityY(double velocityY);


};

class Static_Platform : public Platform {

    Static_Platform();
};

class Horizontal_Platform : public Platform {

    Horizontal_Platform();

};

class Vertical_Platform : public Platform {

    Vertical_Platform();
};

class Temporary_Platform : public Platform {

    Temporary_Platform();
};


#endif //DOODLE_JUMP_PLATFORM_H
