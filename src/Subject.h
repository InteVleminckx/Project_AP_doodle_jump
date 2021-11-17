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


using namespace std;

class Observer;
class Subject {
public:

    vector<Observer>  m_observers; /** Een vector die alle observers van het subject bevat*/

    /**
     * Een constructor.
     */
    Subject();

    /**
     * Function: addObserver(Observer observer)
     * Voegt een observer toe aan de vector van observers van het subject.
     * @param observer: een observer
     */
    void addObserver(const Observer& observer);

    /**
     * Function: removeObserver(Observer observer)
     * Verwijdert een observer uit de vector van observers van het subject.
     * @param observer: een observer
     */
    void removeObserver(const Observer& observer);

    /**
     * Function: Notify()
     * Gaat over alle observer van het subject en roept hier de update function op aan.
     */
    void Notify();

};


#endif //DOODLE_JUMP_SUBJECT_H
