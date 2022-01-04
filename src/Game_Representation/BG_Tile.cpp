#include "BG_Tile.h"

namespace representation {

    BG_Tile::BG_Tile() = default;


    BG_Tile::BG_Tile(shared_ptr<logic::BG_Tile_L> BG_tile, const string& image) : EntityView(BG_tile->getWidth(), BG_tile->getHeight(), image)
    {
        ControllingPointers::control(BG_tile, "BG_Tile", "BG_Tile(shared_ptr<logic::BG_Tile_L> BG_tile, const string& image)");
        setEntityModel(move(BG_tile));

    }

    BG_Tile::~BG_Tile() = default;
}