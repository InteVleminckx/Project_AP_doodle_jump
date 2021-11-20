/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_MODEL_VIEW_H
#define DOODLE_JUMP_MODEL_VIEW_H

#include <iostream>
#include "../Logic_libary/Observer.h"
#include "SFML/Graphics.hpp"

using namespace std;

namespace representation {
class Model_View : public logic::Observer{
    public:

        Model_View();

    };

}



#endif //DOODLE_JUMP_MODEL_VIEW_H
