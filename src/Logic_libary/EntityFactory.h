//
// Created by inte on 11/25/21.
//

#ifndef DOODLE_JUMP_ENTITYFACTORY_H
#define DOODLE_JUMP_ENTITYFACTORY_H

#include <iostream>
#include "../Logic_libary/Platform.h"
#include "../Logic_libary/Player.h"
#include "../Logic_libary/BG_Tile.h"
#include "../Logic_libary/Bonus.h"
#include "../Logic_libary/Score.h"

using namespace std;

enum PlatformType{Static_, Horizontal_, Vertical_, Temporary_};
enum BonusType {Rocket_, Spring_};

namespace logic {
    class EntityFactory {

    public:

        EntityFactory();

        virtual void createPlayer(shared_ptr<Player_L>& subject) = 0;
        virtual void createPlatform(shared_ptr<Platform_L>& subject, PlatformType type) = 0;
        virtual void createBG_Tile(shared_ptr<BG_Tile_L>& subject) = 0;
        virtual void createBonus(shared_ptr<Bonus_L>& subject, BonusType type) = 0;
        virtual void createScore(shared_ptr<Player_L>& subject, shared_ptr<Score>& score) = 0;

    };
}


#endif //DOODLE_JUMP_ENTITYFACTORY_H
