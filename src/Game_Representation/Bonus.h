//
// Created by inte on 11/23/21.
//

#ifndef DOODLE_JUMP_BONUS_H
#define DOODLE_JUMP_BONUS_H

#include <iostream>
#include "EntityView.h"

using namespace std;

namespace representation {
    class Bonus : public EntityView {
    public:

        Bonus();

        void update(float,float) override;

    };
}


#endif //DOODLE_JUMP_BONUS_H
