/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

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

        void createPlayer(shared_ptr<logic::Player_L> &subject) override;
        void createBG_Tile(shared_ptr<logic::BG_Tile_L> &subject) override;
        void createPlatform(shared_ptr<logic::Platform_L> &subject, _Platform type) override;
        void createBonus(shared_ptr<logic::Bonus_L> &subject, _Bonus type) override;
        void createScore(shared_ptr<logic::Player_L> &subject, shared_ptr<logic::Score>& score) override;

    };
}


#endif //DOODLE_JUMP_CONCRETEFACTORY_H
