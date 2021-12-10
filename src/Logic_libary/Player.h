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
#include "Stopwatch.h"
#include <cmath>

using namespace std;

namespace logic {

    class Player_L : public EntityModel {

        float m_jumpforce{.5f};
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
        void gravity() override;

        /**
         * Function: moveRight()
         * Verplaatst de player naar rechts.
         */
        void moveRight() override;

        /**
         * Function: moveLeft()
         * Verplaatst de player naar links.
         */
        void moveLeft() override;


        void jump() override;

    };

}




#endif //DOODLE_JUMP_PLAYER_L_H
