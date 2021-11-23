/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_PLAYER_G_H
#define DOODLE_JUMP_PLAYER_G_H

#include "Entity_View.h"
#include "../Logic_libary/Player.h"

using namespace std;

namespace representation {
    class Player : public Entity_View {

    protected:

        Player();

    public:

        Player(logic::Subject& subject);

        void update() override;

    };
}




#endif //DOODLE_JUMP_PLAYER_G_H
