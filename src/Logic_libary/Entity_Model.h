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

namespace logic {
    class Entity_Model : public Subject {

        float m_x, m_y, m_velocityX, m_velocityY;
        double m_lenght, m_width;

    public:

        /**
         * Is een constructor.
         */
        Entity_Model();

        /**
         * Function: setX(double x)
         * Geeft een x waarde aan de entity
         * @param x: is een float
         */
        void setX(float x);

        /**
         * Function: setY(double y)
         * Geeft een y waarde aan de entity
         * @param y: is een float
         */
        void setY(float y);

        /**
         * Function: setVelocityX(double velocityX)
         * Geeft een velocity in de x richting aan de entity
         * @param velocityX: is een float
         */
        void setVelocityX(float velocityX);

        /**
         * Function: setVelocityY(double velocityY)
         * Geeft een velocity in de y richting aan de entity
         * @param velocityY: is een float
         */
        void setVelocityY(float velocityY);

        /**
         * Function: setLenght(double lenght)
         * Geeft de entity een hoogte.
         * @param lenght: is een double.
         */
        void setLenght(double lenght);

        /**
         * Function: setWidth(double width)
         * Geeft de entity een breedte.
         * @param width: is een double.
         */
        void setWidth(double width);

        /**
         * Function: getX()
         * Geeft de x waarde van de entity terug.
         * @return float
         */
        float getX() const;

        /**
         * Function: getY()
         * Geeft de y waarde van de entity terug.
         * @return float
         */
        float getY() const;

        /**
         * Function: getVelocityX()
         * Geeft de velocityX waarde van de entity terug.
         * @return float
         */
        float getVelocityX() const;

        /**
         * Function: getVelocityY()
         * Geeft de velocityY waarde van de entity terug.
         * @return float
         */
        float getVelocityY() const;

        /**
         * Function: getLenght()
         * Geeft de hoogte van de entity terug.
         * @return double
         */
        double getLenght() const;

        /**
         * Function: getWidth()
         * Geeft de breedte van de entity terug.
         * @return double
         */
        double getWidth() const;

        /**
         * Function: moveRight()
         * Verplaatst de entity naar rechts.
         */
        virtual void moveRight();

        /**
         * Function: moveLeft()
         * Verplaatst de entity naar links.
         */
        virtual void moveLeft();

    };
}



#endif //DOODLE_JUMP_ENTITY_MODEL_H