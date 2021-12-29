/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Subject
 * @BaseClass none
 * @SubClasses EntityModel
 * @Namespace logic
 * @brief  Is Observeerbaar, er kunnen dus 0 of meer observers gelinkt zijn aan een subject
 Heeft drie functionaliteiten:
 1) Add: voegt een observer toe aan het subject
 2) Remove: verwijdert een observer
 3) Notify: roept de observer aan wanneer nodig
 ****************************************************************************************************/
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

        /****************************************************************************************************
         * @brief Een vector die alle observers van het subject bevat
         * @type vector<shared_ptr<Observer>>
         * @var m_observers
         ****************************************************************************************************/
        vector<shared_ptr<Observer>> m_observers;

    public:

        /****************************************************************************************************
         * @function Subject()
         * @brief Een default constructor.
         ****************************************************************************************************/
        Subject();

        /****************************************************************************************************
         * @function void const addObserver(shared_ptr<Observer>& observer)
         * @brief Voegt een observer toe aan de vector van observers van het subject.
         * @param observer: is een const shared_ptr naar een observer die wordt toegevoegd.
         ****************************************************************************************************/
        void addObserver(const shared_ptr<Observer>& observer);

        /****************************************************************************************************
         * @function void removeObserver(const shared_ptr<Observer>& observer)
         * @brief Verwijdert een observer uit de vector van observers van het subject.
         * @param observer: is een const shared_ptr die uit de vector wordt verwijderd.
         ****************************************************************************************************/
        void removeObserver(const shared_ptr<Observer>& observer);

        /****************************************************************************************************
         * @function virtual void Notify()
         * @brief Gaat over alle observer van het subject en roept hier de update function op aan.
         * Het is een pure virtual void en wordt in de EntityModel class overschreven.
         ****************************************************************************************************/
        virtual void Notify() = 0;

        /****************************************************************************************************
         * @function void emptyObserver()
         * @brief Verwijderd alle observers uit zijn vector.
         ****************************************************************************************************/
        void emptyObserver();

        /****************************************************************************************************
         * @function vector<shared_ptr<Observer>>& getObservers()
         * @brief Geeft een vector van observers terug die behoren tot het subject.
         * @return: vector<shared_ptr<Observer>> wat alle observers van het subject bevat.
         * @return: vector<shared_ptr<Observer>> wat alle observers van het subject bevat.
         ****************************************************************************************************/
        vector<shared_ptr<Observer>>& getObservers();

        virtual ~Subject();



    };
}


#endif //DOODLE_JUMP_SUBJECT_H
