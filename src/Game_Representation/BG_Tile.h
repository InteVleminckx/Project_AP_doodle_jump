//
// Created by inte on 11/23/21.
//

#ifndef DOODLE_JUMP_BG_TILE_H
#define DOODLE_JUMP_BG_TILE_H

#include <iostream>
#include "Entity_View.h"

using namespace std;

namespace representation {
    class BG_Tile : public Entity_View {
    public:

        BG_Tile();

        void update() override;

    };


}


#endif //DOODLE_JUMP_BG_TILE_H
