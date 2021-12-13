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
#include "Random.h"
#include <memory>
#include "Camera.h"

using namespace std;

namespace logic {
    class World {

        vector<shared_ptr<Bonus_L>> m_bonussen;
        vector<shared_ptr<Platform_L>> m_platforms;
        vector<shared_ptr<BG_Tile_L>> m_BGtiles;
        shared_ptr<Player_L> m_player;

    public:

        World();

        void createPlayer(shared_ptr<EntityFactory> &factory);

        void createPlatform(shared_ptr<EntityFactory> &factory, float y);

        void createBonus(shared_ptr<EntityFactory> &factory);

        void createBG_Tile(shared_ptr<EntityFactory> &factory);

        void removePlatform(shared_ptr<Platform_L>& platform);

        //----------- Player -----------//

        void movePlayerRight();

        void movePlayerLeft();

        bool playerTouchesPlatform();

        //------------ Player -----------//

        void updateEntities();

        void releaseObservers();

        void getPointsBetweenFrames(vector<pair<float, float>>& left, vector<pair<float, float>>& right, const shared_ptr<Player_L>& subject);
    };
}

#endif //DOODLE_JUMP_WORLD_H
