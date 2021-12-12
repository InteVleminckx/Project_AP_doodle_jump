/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_BG_TILE_H
#define DOODLE_JUMP_BG_TILE_H

#include <iostream>
#include "EntityView.h"

using namespace std;

namespace representation {
    class BG_Tile : public EntityView {

        BG_Tile();

    public:

        BG_Tile(shared_ptr<logic::Subject>& subject);

    };


}


#endif //DOODLE_JUMP_BG_TILE_H
