/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_BONUS_H
#define DOODLE_JUMP_BONUS_H

#include <iostream>
#include "EntityView.h"


using namespace std;

namespace representation {
    class Bonus : public EntityView {
    protected:
        Bonus();
    public:

        Bonus(shared_ptr<logic::Bonus_L>& bonus, string& image);

    };

    class Spring : public Bonus {
        Spring();

    public:
        Spring(shared_ptr<logic::Bonus_L>& bonus, string image);
    };

    class Rocket : public Bonus {
        Rocket();

    public:
        Rocket(shared_ptr<logic::Bonus_L>& bonus, string image);
    };
}


#endif //DOODLE_JUMP_BONUS_H
