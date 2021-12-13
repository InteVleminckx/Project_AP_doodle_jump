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
#include "Camera.h"
#include "Stopwatch.h"

using namespace std;

namespace logic {

    class EntityModel : public Subject {
        float m_x{}, m_y{}, m_xPrev{}, m_yPrev{}, m_velocityX{}, m_velocityY{}, m_height{}, m_width{}, m_gravity{};
        int m_projectedX{}, m_projectedY{};
    public:

        /**
         * Is een constructor.
         */
        EntityModel();

        /**
         * Function: setX(float x)
         * Geeft een x waarde aan de entity
         * @param x: is een float
         */
        void setX(float x);

        /**
         * Function: setY(float y)
         * Geeft een y waarde aan de entity
         * @param y: is een float
         */
        void setY(float y);

        /**
         * Function: setX(float x)
         * Geeft een x waarde aan de entity
         * @param x: is een float
         */
        void setXprev(float x);

        /**
         * Function: setY(float y)
         * Geeft een y waarde aan de entity
         * @param y: is een float
         */
        void setYprev(float y);

        /**
         * Function: projectPointsToPixels()
         * Zet de huidige punten om naar pixels.
         */
        void projectPointsToPixels();

        /**
         * Function: setVelocityX(float velocityX)
         * Geeft een velocity in de x richting aan de entity
         * @param velocityX: is een float
         */
        void setVelocityX(float velocityX);

        /**
         * Function: setVelocityY(float velocityY)
         * Geeft een velocity in de y richting aan de entity
         * @param velocityY: is een float
         */
        void setVelocityY(float velocityY);

        /**
         * Function: setheight(float height)
         * Geeft de entity een hoogte.
         * @param height: is een float.
         */
        void setHeight(float height);

        /**
         * Function: setWidth(float width)
         * Geeft de entity een breedte.
         * @param width: is een float.
         */
        void setWidth(float width);

        /**
         * Function: setGravity(float gravity)
         * Geeft een waarde aan de gravity.
         * @param gravity: is een float.
         */
        void setGravity(float gravity);

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
         * Function: getX()
         * Geeft de x waarde van de entity terug.
         * @return float
         */
        float getXprev() const;

        /**
         * Function: getY()
         * Geeft de y waarde van de entity terug.
         * @return float
         */
        float getYprev() const;

        /**
         * Function: getProjectedX()
         * Geeft de geprojecteerde x waarde van de entity terug.
         * @return int
         */
        int getProjectedX() const;

        /**
         * Function: getProjectedY()
         * Geeft de geprojecteerde y waarde van de entity terug.
         * @return int
         */
        int getProjectedY() const;

        /**
         * Function: getVelocityX()
         * Geeft de velocityX waarde van de entity terug.
         * @return float
         */
        float getVelocityX() const ;

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
        float getHeight() const;

        /**
         * Function: getWidth()
         * Geeft de breedte van de entity terug.
         * @return float
         */
        float getWidth() const;

        /**
         * Function: getGravity()
         * Geeft de waarde van de gravity terug.
         * @return float
         */
        float getGravity() const;

        void Notify() override;

    };
}



#endif //DOODLE_JUMP_ENTITYMODEL_H