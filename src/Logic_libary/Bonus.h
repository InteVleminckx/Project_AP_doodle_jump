/****************************************************************************************************
 * @author Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Bonus
 * @BaseClass EntityModel
 * @SubClasses Spring, Rocket
 * @Namespace logic
 * @brief Is een subclass van EntityModel. Het bevat alle informatie over een Bonus.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_BONUS_L_H
#define DOODLE_JUMP_BONUS_L_H

#include <iostream>
#include "EntityModel.h"

using namespace std;

namespace logic {

    class Bonus_L : public EntityModel {

    protected:

        /****************************************************************************************************
         * @brief Is de kracht van de Bonus waarmee de Player afgevoerd wordt.
         * @type float
         * @var m_bonusforce
         ****************************************************************************************************/
        float m_bonusforce{};

        /****************************************************************************************************
         * @brief Bepaald of de bonus gepakt kan worden als we nog omhoog aan het gaan zijn of niet.
         * @type bool
         * @var m_involmsVelocity
         ****************************************************************************************************/
        bool m_involmsVeloctiy;

    public:

        /****************************************************************************************************
         * @function Bonus_L(float posX, float posY, float width, float height)
         * @brief De construct van Bonus_L waar de argumenten hiervan de informatie over de Bonus zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Bonus.
         * @param height: is een float, het is de hoogte van de Bonus.
         ****************************************************************************************************/
        Bonus_L(float posX, float posY, float width, float height);

        /****************************************************************************************************
         * @function getForce()
         * @brief Geeft de bonusforce terug.
         * @return een float, wat de m_bonusforce is.
         ****************************************************************************************************/
        float getForce();

        /****************************************************************************************************
         * @function getInvolmsVelocity()
         * @brief Geeft een boolean terug die beslist of de bonus gepakt kan worden als de player omhoog gaat.
         * @return een bool, wat de m_involmsVelocity is.
         ****************************************************************************************************/
        bool getInvolmsVelocity();

    };

    class Spring_L : public Bonus_L {
    public:

        /****************************************************************************************************
         * @function Spring_L(float posX, float posY, float width, float height)
         * @brief De construct van Spring_L waar de argumenten hiervan de informatie over de Spring zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Spring.
         * @param height: is een float, het is de hoogte van de Spring.
         ****************************************************************************************************/
        Spring_L(float posX, float posY, float width, float height);
    };

    class Rocket_L : public Bonus_L {
    public:

        /****************************************************************************************************
         * @function Rocket_L(float posX, float posY, float width, float height)
         * @brief De construct van Rocket_L waar de argumenten hiervan de informatie over de Rocket zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Rocket.
         * @param height: is een float, het is de hoogte van de Rocket.
         ****************************************************************************************************/
        Rocket_L(float posX, float posY, float width, float height);
    };
}




#endif //DOODLE_JUMP_BONUS_L_H
