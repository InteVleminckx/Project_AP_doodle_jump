//
// Created by inte on 11/4/21.
//

#ifndef DOODLE_JUMP_ENTITY_H
#define DOODLE_JUMP_ENTITY_H

#include <iostream>


using namespace std;

class Entity {
    double m_x;
    double m_y;
public:

    Entity();

    /**
     * Geeft de x waarde van de entity
     * @return: double, m_x
     */
    double getX();

    /**
     * Geeft de y waarde van de entity
     * @return: double, m_y
     */
    double getY();

    /**
     * Kent een opgeven x waarde toe aan de entity
     * @param x: double, de x waarde die wordt toegekend
     */
    void setX(double x);

    /**
     * Kent een opgeven y waarde toe aan de entity
     * @param y: double, de y waarde die wordt toegekend
     */
    void setY(double y);


};


#endif //DOODLE_JUMP_ENTITY_H
