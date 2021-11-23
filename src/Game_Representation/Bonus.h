//
// Created by inte on 11/23/21.
//

#ifndef DOODLE_JUMP_BONUS_H
#define DOODLE_JUMP_BONUS_H

#include <iostream>
#include "Entity_View.h"

using namespace std;

namespace representation {
    class Bonus : public Entity_View {
    public:

        Bonus();

        void update() override;

    };
}


#endif //DOODLE_JUMP_BONUS_H
