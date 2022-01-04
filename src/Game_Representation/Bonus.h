/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Bonus
 * @BaseClass EntityView
 * @SubClasses Spring, Rocket
 * @Namespace representation
 * @brief Is een subclass van EntityView.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_BONUS_H
#define DOODLE_JUMP_BONUS_H

#include <iostream>
#include "EntityView.h"


using namespace std;

namespace representation {
    class Bonus : public EntityView {

    /****************************************************************************************************
     * @privatesection
     ****************************************************************************************************/

        /****************************************************************************************************
         * @function Bonus()
         * @brief Default constructor
         ****************************************************************************************************/
        Bonus();

    /****************************************************************************************************
     * @publicsection
     ****************************************************************************************************/
    public:

        /****************************************************************************************************
         * @function Bonus(shared_ptr<logic::Bonus_L>& bonus, string& image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param bonus: shared_ptr van een Bonus_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Bonus(shared_ptr<logic::Bonus_L> bonus, string& image);

        /****************************************************************************************************
         * @function ~Bonus()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Bonus() override;

    };

    class Spring : public Bonus {

    /****************************************************************************************************
     * @publicsection
     ****************************************************************************************************/
    public:

        /****************************************************************************************************
         * @function Spring(shared_ptr<logic::Bonus_L>& bonus, string& image)
         * @brief Roept de constructor van Bonus.
         * @param bonus: shared_ptr van een Bonus_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Spring(shared_ptr<logic::Bonus_L> bonus, string image);

        /****************************************************************************************************
         * @function ~Bonus()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Spring() override;
    };

    class Rocket : public Bonus {

    /****************************************************************************************************
     * @publicsection
     ****************************************************************************************************/
    public:

        /****************************************************************************************************
         * @function Rocket(shared_ptr<logic::Bonus_L>& bonus, string& image)
         * @brief Roept de constructor van Bonus.
         * @param bonus: shared_ptr van een Bonus_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Rocket(shared_ptr<logic::Bonus_L> bonus, string image);

        /****************************************************************************************************
         * @function ~Bonus()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Rocket() override;
    };
}


#endif //DOODLE_JUMP_BONUS_H
