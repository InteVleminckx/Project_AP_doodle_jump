/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum 09/01/2022
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
class Player : public EntityView
{

        /****************************************************************************************************
         * @privatesection
         ****************************************************************************************************/

        /****************************************************************************************************
         * @function Player()
         * @brief Default constructor.
         ****************************************************************************************************/
        Player();

        /****************************************************************************************************
         * @publicsection
         ****************************************************************************************************/
public:
        /****************************************************************************************************
         * @function Player(shared_ptr<logic::Player_L> &player, string image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param player: shared_ptr van een Player_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Player(shared_ptr<logic::Player_L> player, const string& image);

        /****************************************************************************************************
         * @function ~Player()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Player() override;
};
} // namespace representation

#endif // DOODLE_JUMP_PLAYER_G_H
