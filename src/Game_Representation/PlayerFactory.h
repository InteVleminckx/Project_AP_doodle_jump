//
// Created by inte on 11/25/21.
//

#ifndef DOODLE_JUMP_PLAYERFACTORY_H
#define DOODLE_JUMP_PLAYERFACTORY_H

#include <iostream>
#include "../Logic_libary/EntityFactory.h"
#include "../Game_Representation/Player.h"

using namespace std;

namespace representation {
    class PlayerFactory : public logic::EntityFactory {
    public:

        PlayerFactory();

        void createPlayer(shared_ptr<logic::Subject> &subject) override;

        void createBG_Tile(shared_ptr<logic::Subject> &subject) override;
        void createPlatform(shared_ptr<logic::Subject> &subject) override;
        void createBonus(shared_ptr<logic::Subject> &subject) override;


    };
}


#endif //DOODLE_JUMP_PLAYERFACTORY_H
