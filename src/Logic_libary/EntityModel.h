/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_ENTITYMODEL_H
#define DOODLE_JUMP_ENTITYMODEL_H

#include <iostream>
#include "Subject.h"
#include "Observer.h"

using namespace std;

namespace logic {

    class EntityModel : public Subject {

    protected:
        float m_x{}, m_y{}, m_velocityX{}, m_velocityY{}, m_height{}, m_width{}, m_gravity{};

    public:

        /**
         * Is een constructor.
         */
        EntityModel();

        /**
         * Function: setX(double x)
         * Geeft een x waarde aan de entity
         * @param x: is een float
         */
        void setX(float x) override;

        /**
         * Function: setY(double y)
         * Geeft een y waarde aan de entity
         * @param y: is een float
         */
        void setY(float y) override;

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
         * Function: setheight(double height)
         * Geeft de entity een hoogte.
         * @param height: is een float.
         */
        void setHeight(float height) override;

        /**
         * Function: setWidth(double width)
         * Geeft de entity een breedte.
         * @param width: is een float.
         */
        void setWidth(float width) override;

        /**
         * Function: getX()
         * Geeft de x waarde van de entity terug.
         * @return float
         */
        float getX() const override;

        /**
         * Function: getY()
         * Geeft de y waarde van de entity terug.
         * @return float
         */
        float getY() const override;

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
         * Function: getHeight()
         * Geeft de hoogte van de entity terug.
         * @return float
         */
        float getHeight() const override;

        /**
         * Function: getWidth()
         * Geeft de breedte van de entity terug.
         * @return float
         */
        float getWidth() const override;

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



#endif //DOODLE_JUMP_ENTITYMODEL_H