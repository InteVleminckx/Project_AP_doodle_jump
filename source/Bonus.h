//
// Created by inte on 11/4/21.
//

#ifndef DOODLE_JUMP_BONUS_H
#define DOODLE_JUMP_BONUS_H

#include <iostream>
#include "Entity.h"

using namespace std;

class Bonus : public Entity {
public:

    Bonus();

};

class Spring : public Bonus {

};

class Jetpack : public Bonus {

};


#endif //DOODLE_JUMP_BONUS_H
