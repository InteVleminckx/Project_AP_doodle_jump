/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_ENTITY_MODEL_H
#define DOODLE_JUMP_ENTITY_MODEL_H

#include <iostream>
#include "Subject.h"

using namespace std;

class Entity_Model : public Subject {

    double m_x, m_y, m_velocityX, m_velocityY, m_lenght, m_width;

public:

    /**
     * Is een constructor.
     */
    Entity_Model();

    /**
     * Geeft een x waarde aan de entity
     * @param x: is een double
     */
    void setX(double x);

    /**
     * Geeft een y waarde aan de entity
     * @param y: is een double
     */
    void setY(double y);

    /**
     * Geeft een velocity in de x richting aan de entity
     * @param velocityX: is een double
     */
    void setVelocityX(double velocityX);

    /**
     * Geeft een velocity in de y richting aan de entity
     * @param velocityY: is een double
     */
    void setVelocityY(double velocityY);

    /**
     * Geeft de entity een hoogte.
     * @param lenght: is een double.
     */
    void setLenght(double lenght);

    /**
     * Geeft de entity een breedte.
     * @param lenght: is een double.
     */
    void setWidth(double width);

    /**
     * Geeft de x waarde van de entity terug.
     * @return double
     */
    double getX();

    /**
     * Geeft de y waarde van de entity terug.
     * @return double
     */
    double getY();

    /**
     * Geeft de velocityX waarde van de entity terug.
     * @return double
     */
    double getVelocityX();

    /**
     * Geeft de velocityY waarde van de entity terug.
     * @return double
     */
    double getVelocityY();

    /**
     * Geeft de hoogte van de entity terug.
     * @return double
     */
    double getLenght();

    /**
     * Geeft de breedte van de entity terug.
     * @return double
     */
    double getWidth();



};


#endif //DOODLE_JUMP_ENTITY_MODEL_H
