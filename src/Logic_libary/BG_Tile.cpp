#include "BG_Tile.h"

namespace logic {


    BG_Tile::BG_Tile() = default;

    BG_Tile::BG_Tile(float posX, float posY, float width, float height) {
        m_x = posX; m_y = posY;
        m_width = width; m_height = height;
    }
}