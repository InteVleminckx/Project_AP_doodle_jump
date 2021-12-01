/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_WORLD_H
#define DOODLE_JUMP_WORLD_H

#include <iostream>
#include "Stopwatch.h"
#include "EntityFactory.h"
#include "Player.h"
#include "Platform.h"
#include "BG_Tile.h"
#include "Bonus.h"
#include <memory>

using namespace std;

enum _Platform{Static, Horizontal, Vertical, Temporary};
enum _Bonus {Rocket, Spring};

namespace logic {
    class World {

        vector<shared_ptr<Subject>> m_bonussen;
        vector<shared_ptr<Subject>> m_platforms;
        vector<shared_ptr<Subject>> m_BGtiles;
        shared_ptr<Subject> m_player;

    public:

        World();

        void createPlayer(shared_ptr<EntityFactory> &factory);

        void createPlatform(shared_ptr<EntityFactory> &factory, _Platform type);

        void createBonus(shared_ptr<EntityFactory> &factory, _Bonus type);

        void createBG_Tile(shared_ptr<EntityFactory> &factory);

        //----------- Player -----------//

        void movePlayerRight();

        void movePlayerLeft();

        bool playerTouchesPlatform();

        //------------ Player -----------//

        void updateEntities();

        void releaseObservers();
    };
}

#endif //DOODLE_JUMP_WORLD_H
