/**
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class BG_Tile
 * @BaseClass EntityView
 * @SubClasses None
 * @Namespace representation
 * @Description Is een subclass van EntityView.
 */

#ifndef DOODLE_JUMP_BG_TILE_H
#define DOODLE_JUMP_BG_TILE_H

#include <iostream>
#include "EntityView.h"

using namespace std;

namespace representation {
    class BG_Tile : public EntityView {

        /****************************************************************************************************
         * @function BG_Tile()
         * @brief Default constructor.
         ****************************************************************************************************/
        BG_Tile();

    public:

        /****************************************************************************************************
         * @function BG_Tile(shared_ptr<logic::BG_Tile_L>& BG_tile, string image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param BG_tile: shared_ptr van een BG_Tile_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        BG_Tile(shared_ptr<logic::BG_Tile_L> BG_tile, string image);

        ~BG_Tile() override;

    };
}


#endif //DOODLE_JUMP_BG_TILE_H
