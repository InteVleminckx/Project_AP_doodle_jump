#include "BG_Tile.h"

namespace representation {

    BG_Tile::BG_Tile() = default;


    BG_Tile::BG_Tile(shared_ptr<logic::BG_Tile_L> BG_tile, string image) : EntityView(BG_tile->getWidth(), BG_tile->getHeight(), image)
    {
        setEntityModel(move(BG_tile));
    }

    BG_Tile::~BG_Tile() {cout << "delete BG_Tile observer" << endl;}
}