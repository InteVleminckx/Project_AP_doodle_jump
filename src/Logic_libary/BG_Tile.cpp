#include "BG_Tile.h"

namespace logic {


    BG_Tile_L::BG_Tile_L() = default;

    BG_Tile_L::BG_Tile_L(float posX, float posY, float width, float height) {
        setX(posX); setY(posY);
        setWidth(width); setHeight(height);
    }
}