/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
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
    class Observer {
    protected:

        /****************************************************************************************************
         * @function Observer()
         * @brief Is een default constructor.
         ****************************************************************************************************/
        Observer();

    public:

        /****************************************************************************************************
         * @function Update()
         * @brief Updates de huidige staat van het subject.
         * Is een pure virtual void function.
         ****************************************************************************************************/
        virtual void update() = 0;


    };
}




#endif //DOODLE_JUMP_OBSERVER_H
