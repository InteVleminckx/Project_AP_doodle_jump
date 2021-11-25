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

using namespace std;

enum Platform {Static, Horizontal, Vertical, Temporary};
enum Bonus {Rocket, Spring};

namespace logic {
    class World {

        vector<shared_ptr<Subject>> m_entities;

    public:

        World();

        void createPlayer(shared_ptr<EntityFactory> &factory);

        void createPlatform(shared_ptr<EntityFactory> &factory, Platform type);

        void createBonus(shared_ptr<EntityFactory> &factory, Bonus type);

        void createBG_Tile(shared_ptr<EntityFactory> &factory);

        void updateEntities();

        void releaseObservers();
    };
}

#endif //DOODLE_JUMP_WORLD_H
