/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_BG_TILE_L_H
#define DOODLE_JUMP_BG_TILE_L_H

#include <iostream>
#include "EntityModel.h"

using namespace std;

namespace logic {
    class BG_Tile : public EntityModel {
    protected:
    public:
        BG_Tile();
        BG_Tile(float posX, float posY, float width, float height);


    };
}


#endif //DOODLE_JUMP_BG_TILE_L_H
