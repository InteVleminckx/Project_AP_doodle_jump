/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_PLAYER_G_H
#define DOODLE_JUMP_PLAYER_G_H

#include "EntityView.h"
#include "../Logic_libary/Player.h"

using namespace std;

namespace representation {
    class Player : public EntityView {

    protected:

        Player();

    public:

        Player(shared_ptr<logic::Subject> &subject);

        void update(float x, float y) override;

    };
}




#endif //DOODLE_JUMP_PLAYER_G_H
