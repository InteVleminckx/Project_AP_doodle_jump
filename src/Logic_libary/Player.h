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
#include "Counter.h"
#include "Stopwatch.h"

using namespace std;

namespace logic {

    class Player_L : public EntityModel {

//        float m_jumpforce{250.0f};

    public:

        /**
         * Is een constructor.
         */
        Player_L();

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
