/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Player
 * @BaseClass EntityView
 * @SubClasses none
 * @Namespace representation
 * @brief Is een subclass van EntityView.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_PLAYER_G_H
#define DOODLE_JUMP_PLAYER_G_H

#include "EntityView.h"

using namespace std;

namespace representation {
    class Player : public EntityView {

        /****************************************************************************************************
         * @function Player()
         * @brief Default constructor.
         ****************************************************************************************************/
        Player();

    public:

        /****************************************************************************************************
         * @function Player(shared_ptr<logic::Player_L> &player, string image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param player: shared_ptr van een Player_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Player(shared_ptr<logic::Player_L> player, const string& image);

        ~Player() override;
    };
}




#endif //DOODLE_JUMP_PLAYER_G_H
