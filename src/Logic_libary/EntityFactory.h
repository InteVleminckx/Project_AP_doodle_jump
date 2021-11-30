//
// Created by inte on 11/25/21.
//

#ifndef DOODLE_JUMP_ENTITYFACTORY_H
#define DOODLE_JUMP_ENTITYFACTORY_H

#include <iostream>
#include "../Logic_libary/EntityModel.h"

using namespace std;

namespace logic {
    class EntityFactory {

    public:

        EntityFactory();

        virtual void createPlayer(shared_ptr<Subject>& subject) = 0;
        virtual void createPlatform(shared_ptr<Subject>& subject) = 0;
        virtual void createBG_Tile(shared_ptr<Subject>& subject) = 0;
        virtual void createBonus(shared_ptr<Subject>& subject) = 0;

    };
}


#endif //DOODLE_JUMP_ENTITYFACTORY_H
