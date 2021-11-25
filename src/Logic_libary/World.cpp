//
// Created by inte on 11/18/21.
//

#include "World.h"

#include <memory>

namespace logic {


    World::World() {

    }

    void World::createPlayer(shared_ptr<EntityFactory> &factory)
    {
        shared_ptr<logic::Subject> player = std::make_shared<logic::Player_L> ();
        factory->createPlayer(player);
        m_entities.push_back(player);
    }

    void World::createPlatform(shared_ptr<EntityFactory> &factory, Platform type)
    {
        shared_ptr<logic::Subject> platform;
        switch (type) {
            case Static:
                platform = std::make_shared<logic::Platform_L_static> ();
                break;
            case Horizontal:
                 platform = std::make_shared<logic::Platform_L_horizontal> ();
                break;
            case Vertical:
                platform = std::make_shared<logic::Platform_L_vertical> ();
                break;
            case Temporary:
                platform = std::make_shared<logic::Platform_L_temporary> ();
        }
        factory->createPlatform(platform);
        m_entities.push_back(platform);

    }

    void World::createBonus(shared_ptr<EntityFactory> &factory, Bonus type)
    {
        shared_ptr<logic::Subject> bonus;
//        switch (type) {
//            case Rocket:
//
//            case Spring:
//
//        }
    }

    void World::createBG_Tile(shared_ptr<EntityFactory> &factory)
    {
        shared_ptr<logic::Subject> tile = std::make_shared<logic::BG_Tile> ();
        factory->createBG_Tile(tile);
        m_entities.push_back(tile);
    }

    void World::updateEntities() {
        for (const auto& entity : m_entities) entity->Notify();
    }

    void World::releaseObservers() {
        for (const auto& entity : m_entities) entity->emptyObserver();
    }


}