//
// Created by inte_vleminckx on 28.12.21.
//

#ifndef DOODLE_JUMP_CONTROLLING_H
#define DOODLE_JUMP_CONTROLLING_H
#include "Subject.h"

class Controlling {
public:
    static void control(const shared_ptr<logic::Subject>& subject, const string className, const string functionName);

};


#endif //DOODLE_JUMP_CONTROLLING_H
