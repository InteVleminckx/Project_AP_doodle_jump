//
// Created by inte on 11/23/21.
//

#ifndef DOODLE_JUMP_BG_TILE_H
#define DOODLE_JUMP_BG_TILE_H

#include <iostream>
#include "EntityView.h"

using namespace std;

namespace representation {
    class BG_Tile : public EntityView {
    public:

        BG_Tile();

        void update(float,float) override;

    };


}


#endif //DOODLE_JUMP_BG_TILE_H
