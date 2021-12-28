/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class EntityModel
 * @BaseClass Subject
 * @SubClasses Player_L, Platform_L, Bonus_L, BG_Tile_L
 * @Namespace logic
 * @brief Is een subclass van Subject.&
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_ENTITYMODEL_H
#define DOODLE_JUMP_ENTITYMODEL_H

#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include "Camera.h"
#include "Stopwatch.h"
#include "ControllingPointers.h"

using namespace std;

namespace logic {

    class EntityModel : public Subject {

        /****************************************************************************************************
         * @brief Is de postie van een entity.
         * @type float
         * @var m_x, m_y
         ****************************************************************************************************/
        float m_x{}, m_y{};

        /****************************************************************************************************
         * @brief Is de positie van de entity op zijn vorige frame.
         * @type float
         * @var m_xPrev, m_yPrev
         ****************************************************************************************************/
        float m_xPrev{}, m_yPrev{};

        /****************************************************************************************************
         * @brief Is de velocity van de entity.
         * @type float
         * @var m_velocityX, m_velocityY
         ****************************************************************************************************/
        float m_velocityX{}, m_velocityY{};

        /****************************************************************************************************
         * @brief Zijn de afmetingen van de entity.
         * @type float
         * @var m_width, m_height
         ****************************************************************************************************/
        float m_width{}, m_height{};

        /****************************************************************************************************
         * @brief Is de zwaartekracht die inwerkt op de entity.
         * @type float
         * @var m_gravity
         ****************************************************************************************************/
        float m_gravity{};

        /****************************************************************************************************
         * @brief Zijn de geprojecteerde coördinaten van de entity.
         * @type int
         * @var m_projectedX, m_projectedY
         ****************************************************************************************************/
        int m_projectedX{}, m_projectedY{};

    public:

        /****************************************************************************************************
         * @function EntityModel()
         * @brief Is een default constructor.
         ****************************************************************************************************/
        EntityModel();

        /****************************************************************************************************
         * @function void projectPointsToPixels()
         * @brief Zet de huidige punten om naar pixels.
         ****************************************************************************************************/
        void projectPointsToPixels();

        /****************************************************************************************************
         * @function void Notify() override
         * @brief Roept de update functie op van zijn observers.
         ****************************************************************************************************/
        void Notify() override;

        /****************************************************************************************************
         * @function void setX(float x)
         * @brief Geeft een x waarde aan de entity
         * @param x: is een float
         ****************************************************************************************************/

        void setX(float x);

        /****************************************************************************************************
         * @function void setY(float y)
         * @brief Geeft een y waarde aan de entity
         * @param y: is een float
         ****************************************************************************************************/

        void setY(float y);

        /****************************************************************************************************
         * @function void setX(float x)
         * @brief Geeft een x waarde aan de entity
         * @param x: is een float
         ****************************************************************************************************/
        void setXprev(float x);

        /****************************************************************************************************
         * @function void setY(float y)
         * @brief Geeft een y waarde aan de entity
         * @param y: is een float
         ****************************************************************************************************/
        void setYprev(float y);

        /****************************************************************************************************
         * @function void setVelocityX(float velocityX)
         * @brief Geeft een velocity in de x richting aan de entity
         * @param velocityX: is een float
         ****************************************************************************************************/
        void setVelocityX(float velocityX);

        /****************************************************************************************************
         * @function void setVelocityY(float velocityY)
         * @brief Geeft een velocity in de y richting aan de entity
         * @param velocityY: is een float
         ****************************************************************************************************/
        void setVelocityY(float velocityY);

        /****************************************************************************************************
         * @function void setWidth(float width)
         * @brief Geeft de entity een breedte.
         * @param width: is een float.
         ****************************************************************************************************/
        void setWidth(float width);

        /****************************************************************************************************
         * @function void setheight(float height)
         * @brief Geeft de entity een hoogte.
         * @param height: is een float.
         ****************************************************************************************************/
        void setHeight(float height);

        /****************************************************************************************************
         * @function void setGravity(float gravity)
         * @brief Geeft een waarde aan de gravity.
         * @param gravity: is een float.
         ****************************************************************************************************/
        void setGravity(float gravity);

        /****************************************************************************************************
         * @function float getX()
         * @brief Geeft de x waarde van de entity terug.
         * @return is een float die de x waarde teruggeeft.
         ****************************************************************************************************/
        float getX() const;

        /****************************************************************************************************
         * @function float getY()
         * @brief Geeft de y waarde van de entity terug.
         * @return is een float die de y waarde teruggeeft.
         ****************************************************************************************************/
        float getY() const;

        /****************************************************************************************************
         * @function float getX()
         * @brief Geeft de vorige frame x waarde van de entity terug.
         * @return is een float die de vorige frame x waarde teruggeeft.
         ****************************************************************************************************/
        float getXprev() const;

        /****************************************************************************************************
         * @function float getY()
         * @brief Geeft de vorige frame y waarde van de entity terug.
         * @return is een float die vorige frame y waarde terugggeeft.
         ****************************************************************************************************/
        float getYprev() const;

        /****************************************************************************************************
         * @function float getVelocityX()
         * @brief Geeft de velocityX waarde van de entity terug.
         * @return is een float die de velocity in x richting teruggeeft.
         ****************************************************************************************************/
        float getVelocityX() const;

        /****************************************************************************************************
         * @function float getVelocityY()
         * @brief Geeft de velocityY waarde van de entity terug.
         * @return is een float die de velocity in de y richting teruggeeft.
         ****************************************************************************************************/
        float getVelocityY() const;

        /****************************************************************************************************
         * @function float getHeight()
         * @brief Geeft de hoogte van de entity terug.
         * @return is een float die de hoogte teruggeeft.
         ****************************************************************************************************/
        float getHeight() const;

        /****************************************************************************************************
         * @function float getWidth()
         * @brief Geeft de breedte van de entity terug.
         * @return is een float die de breedte teruggeeft.
         ****************************************************************************************************/
        float getWidth() const;

        /****************************************************************************************************
         * @function float getGravity()
         * @brief Geeft de waarde van de gravity terug.
         * @return is een float die de zwaartekracht teruggeeft.
         ****************************************************************************************************/
        float getGravity() const;

        /****************************************************************************************************
         * @function int getProjectedX()
         * @brief Geeft de geprojecteerde x waarde van de entity terug.
         * @return is een int die de geprojecteerde x waarde teruggeeft.
         ****************************************************************************************************/
        int getProjectedX() const;

        /****************************************************************************************************
         * @function int getProjectedY()
         * @brief Geeft de geprojecteerde y waarde van de entity terug.
         * @return is een int die de geprojecteerde y waarde teruggeeft.
         ****************************************************************************************************/
        int getProjectedY() const;

        ~EntityModel() override;

    };
}
#endif //DOODLE_JUMP_ENTITYMODEL_H