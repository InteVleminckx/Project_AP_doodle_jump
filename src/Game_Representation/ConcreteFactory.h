//
// Created by inte on 12/2/21.
//

#ifndef DOODLE_JUMP_CONCRETEFACTORY_H
#define DOODLE_JUMP_CONCRETEFACTORY_H

#include <iostream>
#include "../Logic_libary/EntityFactory.h"
#include "../Game_Representation/Player.h"
#include "../Game_Representation/Platform.h"
#include "../Game_Representation/BG_Tile.h"
#include "../Game_Representation/Bonus.h"

using namespace std;

namespace Representation {
    class ConcreteFactory : public logic::EntityFactory{
    public:

        ConcreteFactory() = default;

        void createPlayer(shared_ptr<logic::Subject> &subject) override;
        void createBG_Tile(shared_ptr<logic::Subject> &subject) override;
        void createPlatform(shared_ptr<logic::Subject> &subject, _Platform type) override;
        void createBonus(shared_ptr<logic::Subject> &subject, _Bonus type) override;

    };
}


#endif //DOODLE_JUMP_CONCRETEFACTORY_H
