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

using namespace std;

namespace representation {
    class Player : public EntityView {

        Player();
    public:

        Player(shared_ptr<logic::Player_L> &player, string image);
    };
}




#endif //DOODLE_JUMP_PLAYER_G_H
