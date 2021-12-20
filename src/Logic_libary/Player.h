/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_PLAYER_L_H
#define DOODLE_JUMP_PLAYER_L_H

#include <iostream>
#include "EntityModel.h"
#include <cmath>

using namespace std;

namespace logic {

    class Player_L : public EntityModel {

        float m_jumpforce{.75f};

        bool m_bonusActive = false;

        /**
         * Is een constructor.
         */
        Player_L();

    public:

        /**
         * Is een constructor.
         */
        Player_L(float posX, float posY, float width, float height);

        /**
         * Function: gravity()
         * Haalt de speler naar beneden, de zwaartekracht werkt op hem.
         */
        void gravity();

        /**
         * Function: moveRight(float leftBound, float rightBound)
         * Verplaatst de player naar rechts.
         * @param: float
         * @param: float
         */
        void moveRight(float leftBound, float rightBound);

        /**
         * Function: moveLeft(float leftBound, float rightBound)
         * Verplaatst de player naar links.
         * @param: float
         * @param: float
         */
        void moveLeft(float leftBound, float rightBound);


        void jump();

        void powerup(float power);

    };

}




#endif //DOODLE_JUMP_PLAYER_L_H
