#include "BG_Tile.h"

namespace representation {

    BG_Tile::BG_Tile() = default;


    BG_Tile::BG_Tile(shared_ptr<logic::BG_Tile_L> &BG_tile, string image) : EntityView(BG_tile->getWidth(), BG_tile->getHeight(), image)
    {
        setEntityModel(BG_tile);
    }
}