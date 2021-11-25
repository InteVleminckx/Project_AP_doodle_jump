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

using namespace std;

namespace logic {

    class Player_L : public EntityModel {

        double m_jumpforce;

    public:

        /**
         * Function: gravity()
         * Haalt de speler naar beneden, de zwaartekracht werkt op hem.
         */
        void gravity();

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

    };

}




#endif //DOODLE_JUMP_PLAYER_L_H
