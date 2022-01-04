/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class ControllingPointers
 * @BaseClass none
 * @SubClasses none
 * @Namespace none
 * @brief Controleert dat pointer geen nullpointers zijn.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_CONTROLLING_H
#define DOODLE_JUMP_CONTROLLING_H

#include <iostream>
#include <memory>
#include "../Exceptions.h"

using namespace std;

class ControllingPointers {

/****************************************************************************************************
 * @publicsection
 ****************************************************************************************************/
public:

    /****************************************************************************************************
     * @function static void control(const shared_ptr<T>& pointer, const string& className, const string& functionName)
     * @brief Controleert een shared_ptr of deze verwijst naar iets of naar niets.
     * @tparam T: Eender welk object van een class.
     * @param pointer: Een shared_ptr naar een class.
     * @param className: De naam van de class waar de functie wordt aangeroepen.
     * @param functionName: De functie waar deze functie wordt aangeroepen.
     ****************************************************************************************************/
    template<class T>
    static void control(const shared_ptr<T>& pointer, const string& className, const string& functionName);
};

template<class T>
void ControllingPointers::control(const shared_ptr<T> &pointer, const string &className, const string &functionName) {
    try {
        if(pointer == nullptr){
            throw nullptrException(className, functionName);
        }
    }
    catch (nullptrException& exception){
        cout << exception.what_() << endl;
        exit(1);
    }
}


#endif //DOODLE_JUMP_CONTROLLING_H


