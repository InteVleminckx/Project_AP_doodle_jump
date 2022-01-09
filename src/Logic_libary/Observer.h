/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum 09/01/2022
 * @Class Observer
 * @BaseClass none
 * @SubClasses EntityView, Score
 * @Namespace logic
 * @brief observeerd wat er gebeurd en wanneer er een wijziging is past deze het aan,aan de hand van een update functie.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_OBSERVER_H
#define DOODLE_JUMP_OBSERVER_H

#include <iostream>

using namespace std;
#include "Subject.h"

namespace logic {
class Observer
{

        /****************************************************************************************************
         * @protectedsection
         ****************************************************************************************************/
protected:
        /****************************************************************************************************
         * @function Observer()
         * @brief Is een default constructor.
         ****************************************************************************************************/
        Observer();

        /****************************************************************************************************
         * @publicsection
         ****************************************************************************************************/
public:
        /****************************************************************************************************
         * @function Update()
         * @brief Updates de huidige staat van het subject.
         * Is een pure virtual void function.
         ****************************************************************************************************/
        virtual void update() = 0;

        /****************************************************************************************************
         * @function ~Observer()
         * @brief Is een virtual destructor.
         ****************************************************************************************************/
        virtual ~Observer();
};
} // namespace logic

#endif // DOODLE_JUMP_OBSERVER_H
