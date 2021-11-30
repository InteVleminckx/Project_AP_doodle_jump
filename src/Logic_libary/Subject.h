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
    public:

        vector<shared_ptr<Observer>> m_observers; /** Een vector die alle observers van het subject bevat*/

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

        virtual void moveRight() = 0;

        virtual void moveLeft() = 0;

        virtual void setX(float x)  = 0;

        virtual void setY(float y) = 0;

        virtual void jump() = 0;

        virtual float getY() const = 0;

        virtual float getX() const = 0;

        virtual void gravity() = 0;

        virtual void setWidth(float ) = 0;

        virtual void setHeight(float ) = 0;

        virtual float getWidth() const = 0;

        virtual float getHeight() const = 0;

        void emptyObserver();


    };
}


#endif //DOODLE_JUMP_SUBJECT_H
