/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_BONUS_L_H
#define DOODLE_JUMP_BONUS_L_H

#include <iostream>
#include "EntityModel.h"

using namespace std;

namespace logic {
    class Bonus_L : public EntityModel {
    protected:
        float m_bonusforce{};
        bool m_involmsVeloctiy; //bepaald of de bonus gepakt kan worden als we nog omhoog aan het gaan zijn of niet

        Bonus_L();
    public:
        Bonus_L(float posX, float posY, float width, float height);

        float getForce();

        bool getInvolmsVelocity();

    };

    class Spring_L : public Bonus_L {
        Spring_L();
    public:
        Spring_L(float posX, float posY, float width, float height);
    };

    class Rocket_L : public Bonus_L {
        Rocket_L();
    public:
        Rocket_L(float posX, float posY, float width, float height);
    };
}




#endif //DOODLE_JUMP_BONUS_L_H
