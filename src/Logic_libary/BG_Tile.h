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
    class BG_Tile_L : public EntityModel {
    protected:
    public:
        BG_Tile_L();
        BG_Tile_L(float posX, float posY, float width, float height);


    };
}


#endif //DOODLE_JUMP_BG_TILE_L_H
