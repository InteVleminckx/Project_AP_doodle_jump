/****************************************************************************************************
 * @author Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Player_L
 * @BaseClass EntityModel
 * @SubClasses none
 * @Namespace logic
 * @brief Is een subclass van EntityModel. Het bevat alle informatie over de Player.
 ****************************************************************************************************/
#ifndef DOODLE_JUMP_PLAYER_L_H
#define DOODLE_JUMP_PLAYER_L_H

#include <iostream>
#include "EntityModel.h"
#include <cmath>

using namespace std;

namespace logic {

    class Player_L : public EntityModel {

        /****************************************************************************************************
         * @brief Is de kracht waarmee de speler springt.
         * @type float
         * @var m_jumpforce
         ****************************************************************************************************/
        float m_jumpforce{.75f};

        /****************************************************************************************************
         * @brief Zegt als een bonus actief, als dat zo is kan er geen andere bonus gepakt worden.
         * @type bool
         * @var m_bonusActive
         ****************************************************************************************************/
        bool m_bonusActive = false;


    public:

        /****************************************************************************************************
         * @function Player_L(float posX, float posY, float width, float height)
         * @brief De construct van Player_L waar de argumenten hiervan de informatie over de Player zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Player.
         * @param height: is een float, het is de hoogte van de Player.
         ****************************************************************************************************/
        Player_L(float posX, float posY, float width, float height);

        /****************************************************************************************************
         * @function void gravity()
         * @brief Haalt de speler naar beneden, de zwaartekracht werkt op hem.
         ****************************************************************************************************/
        void gravity();

        /****************************************************************************************************
         * @function void moveRight(float leftBound, float rightBound)
         * @brief Verplaatst de player naar rechts.
         * @param leftBound: is een float, is de linkerkant van het logic coördinaatsysteem.
         * @param: rightBound: is een float, is de rechterkant van het logic coördinaatsysteem.
         ****************************************************************************************************/
        void moveRight(float leftBound, float rightBound);

        /****************************************************************************************************
         * @function void moveLeft(float leftBound, float rightBound)
         * @brief Verplaatst de player naar links.
         * @param leftBound: is een float, is de linkerkant van het logic coördinaatsysteem.
         * @param: rightBound: is een float, is de rechterkant van het logic coördinaatsysteem.
         ****************************************************************************************************/
        void moveLeft(float leftBound, float rightBound);

        /****************************************************************************************************
         * @function void jump()
         * @brief Zorgt ervoor dat de speler kan springen.
         ****************************************************************************************************/
        void jump();

        /****************************************************************************************************
         * @function void powerup(float power)
         * @brief Zorgt ervoor dat de speler een boost kan accepteren.
         * @param power: is een float, is de boost waarde.
         ****************************************************************************************************/
        void powerup(float power);

    };

}




#endif //DOODLE_JUMP_PLAYER_L_H
