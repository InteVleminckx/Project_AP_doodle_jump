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
    protected:

        /****************************************************************************************************
         * @function Bonus()
         * @brief Default constructor
         ****************************************************************************************************/
        Bonus();

    public:

        /****************************************************************************************************
         * @function Bonus(shared_ptr<logic::Bonus_L>& bonus, string& image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param bonus: shared_ptr van een Bonus_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Bonus(shared_ptr<logic::Bonus_L>& bonus, string& image);

    };

    class Spring : public Bonus {

        /****************************************************************************************************
         * @function Spring()
         * @brief Default constructor.
         ****************************************************************************************************/
        Spring();

    public:

        /****************************************************************************************************
         * @function Spring(shared_ptr<logic::Bonus_L>& bonus, string& image)
         * @brief Roept de constructor van Bonus.
         * @param bonus: shared_ptr van een Bonus_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Spring(shared_ptr<logic::Bonus_L>& bonus, string image);
    };

    class Rocket : public Bonus {

        /****************************************************************************************************
         * @function Rocket()
         * @brief Default constructor
         ****************************************************************************************************/
        Rocket();

    public:

        /****************************************************************************************************
         * @function Rocket(shared_ptr<logic::Bonus_L>& bonus, string& image)
         * @brief Roept de constructor van Bonus.
         * @param bonus: shared_ptr van een Bonus_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Rocket(shared_ptr<logic::Bonus_L>& bonus, string image);
    };
}


#endif //DOODLE_JUMP_BONUS_H
