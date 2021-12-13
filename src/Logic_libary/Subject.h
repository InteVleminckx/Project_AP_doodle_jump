/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 * Is Observeerbaar, er kunnen dus 0 of meer observers gelinkt zijn aan een subject
 * Heeft drie functionaliteiten:
 * 1) Add: voegt een observer toe aan het subject
 * 2) Remove: verwijdert een observer
 * 3) Notify: roept de observer aan wanneer nodig
 */

#ifndef DOODLE_JUMP_SUBJECT_H
#define DOODLE_JUMP_SUBJECT_H

#include <iostream>
#include <vector>
#include <memory>
#include "../Game_Representation/Window.h"

using namespace std;

namespace logic {
    class Observer;
    class Subject {
    public: //ToDo: Nog protected/private maken en hiervoor nog een getFunctie voor makes als dit nodig is
        vector<shared_ptr<Observer>> m_observers; /** Een vector die alle observers van het subject bevat*/

    public:

        /**
         * Een constructor.
         */
        Subject();

        /**
         * Function: addObserver(Observer observer)
         * Voegt een observer toe aan de vector van observers van het subject.
         * @param observer: een observer
         */
        void addObserver(const shared_ptr<Observer>& observer);

        /**
         * Function: removeObserver(Observer observer)
         * Verwijdert een observer uit de vector van observers van het subject.
         * @param observer: een observer
         */
        void removeObserver(const shared_ptr<Observer>& observer);

        /**
         * Function: Notify()
         * Gaat over alle observer van het subject en roept hier de update function op aan.
         */
        virtual void Notify() = 0;

        /**
         * Function: emptyObserver()
         * Verwijderd alle observers uit zijn vector.
         */
        void emptyObserver();


    };
}


#endif //DOODLE_JUMP_SUBJECT_H
