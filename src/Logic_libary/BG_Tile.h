/****************************************************************************************************
 * @author Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class BG_Tile_L
 * @BaseClass EntityModel
 * @SubClasses none
 * @Namespace logic
 * @brief Is een subclass van EntityModel. Het bevat alle informatie over de BG_Tile.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_BG_TILE_L_H
#define DOODLE_JUMP_BG_TILE_L_H

#include <iostream>
#include "EntityModel.h"

using namespace std;

namespace logic {

    class BG_Tile_L : public EntityModel {

    /****************************************************************************************************
     * @publicsection
     ****************************************************************************************************/
    public:

        /****************************************************************************************************
         * @function BG_Tile_L(float posX, float posY, float width, float height)
         * @brief De construct van BG_Tile_L waar de argumenten hiervan de informatie over de BG_Tile zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de BG_Tile.
         * @param height: is een float, het is de hoogte van de BG_Tile.
         ****************************************************************************************************/
        BG_Tile_L(float posX, float posY, float width, float height);

        /****************************************************************************************************
         * @function ~BG_Tile_L()
         * @brief Default destructor
         ****************************************************************************************************/
        ~BG_Tile_L() override;

    };

}


#endif //DOODLE_JUMP_BG_TILE_L_H
