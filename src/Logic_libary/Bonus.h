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
    class Bonus : public EntityModel {
    protected:
        float m_bonusforce{};
        Bonus();
    public:
        Bonus(float posX, float posY, float width, float height);
    };

    class Spring : public Bonus {
        Spring();
    public:
        Spring(float posX, float posY, float width, float height);
    };

    class Rocket : public Bonus {
        Rocket();
    public:
        Rocket(float posX, float posY, float width, float height);
    };
}




#endif //DOODLE_JUMP_BONUS_L_H
