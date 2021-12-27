#include "BG_Tile.h"

namespace logic {

    BG_Tile_L::BG_Tile_L(float posX, float posY, float width, float height) {
        setX(posX); setY(posY);
        setWidth(width); setHeight(height);
    }

    BG_Tile_L::~BG_Tile_L() {
        cout << "delete BG_tile Logic" << endl;
    }
}