//
// Created by inte_vleminckx on 28.12.21.
//

#ifndef DOODLE_JUMP_CONTROLLING_H
#define DOODLE_JUMP_CONTROLLING_H


#include "Observer.h"
#include "Subject.h"
#include "EntityFactory.h"

class ControllingPointers {
public:

//    template<typename T>
//    static void control(const shared_ptr<T>& pointer, const string& className, const string& functionName);
    static void control(const shared_ptr<logic::Subject>& subject, const string& className, const string& functionName);

    static void control(const shared_ptr<logic::Observer>& observer, const string& className, const string& functionName);

    static void control(const shared_ptr<logic::EntityFactory>& factory, const string& className, const string& functionName);


};


#endif //DOODLE_JUMP_CONTROLLING_H


