/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 * Observeerd wat er gebeurd en wanneer er een wijziging is past deze het aan,
 * aan de hand van een update functie.
 */

#ifndef DOODLE_JUMP_OBSERVER_H
#define DOODLE_JUMP_OBSERVER_H

#include <iostream>

using namespace std;
#include "Subject.h"


class Observer {

    Subject m_subject;

public:

    /**
     * Is een constructor.
     */
    Observer(Subject& subject);

    /**
     * Function: Update()
     * Updates de huidige staat van het subject.
     */
    void Update();

    bool operator==(const Observer& that);

};


#endif //DOODLE_JUMP_OBSERVER_H
