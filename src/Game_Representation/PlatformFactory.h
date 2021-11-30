//
// Created by inte on 11/25/21.
//

#ifndef DOODLE_JUMP_PLATFORMFACTORY_H
#define DOODLE_JUMP_PLATFORMFACTORY_H

#include <iostream>
#include "../Logic_libary/EntityFactory.h"
#include "../Game_Representation/Platform.h"

using namespace std;

namespace representation {
    class PlatformFactory : public logic::EntityFactory {
    public:

        PlatformFactory();

        void createPlayer(shared_ptr<logic::Subject> &subject) override {};
        void createBG_Tile(shared_ptr<logic::Subject> &subject) override {};
        void createPlatform(shared_ptr<logic::Subject> &subject) override;
        void createBonus(shared_ptr<logic::Subject> &subject) override {};

    };

}

#endif //DOODLE_JUMP_PLATFORMFACTORY_H
