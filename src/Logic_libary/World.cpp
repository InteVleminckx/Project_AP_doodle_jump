//
// Created by inte on 11/18/21.
//

#include "World.h"

namespace logic {


    World::World() {

    }

    void World::createPlayer(shared_ptr<EntityFactory> &factory)
    {
        m_player = std::make_shared<logic::Player_L> ();
        factory->createPlayer(m_player);
    }

    void World::createPlatform(shared_ptr<EntityFactory> &factory, _Platform type)
    {
        shared_ptr<logic::Subject> platform;
        switch (type) {
            case Static:
                platform = make_shared<logic::Platform_L_static>();
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
        m_platforms.push_back(platform);
    }

    void World::createBonus(shared_ptr<EntityFactory> &factory, _Bonus type)
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
        m_BGtiles.push_back(tile);
    }

    void World::updateEntities() {
        m_player->Notify();
        m_player->gravity();
        if (playerTouchesPlatform()) m_player->jump();
        for (const auto& entity : m_BGtiles) entity->Notify();
        for (const auto& entity : m_platforms) entity->Notify();
        for (const auto& entity : m_bonussen) entity->Notify();
    }

    void World::releaseObservers() {
        m_player->emptyObserver();
        for (const auto& entity : m_BGtiles) entity->emptyObserver();
        for (const auto& entity : m_platforms) entity->emptyObserver();
        for (const auto& entity : m_bonussen) entity->emptyObserver();
    }

    void World::movePlayerRight() {
        m_player->moveRight();
    }

    void World::movePlayerLeft() {
        m_player->moveLeft();

    }

    bool World::playerTouchesPlatform() {
        for (const auto &platform : m_platforms)
        {
            //kleine marge
            if (platform->getY() - 5.0f < m_player->getY() + m_player->getHeight() &&  m_player->getY() + m_player->getHeight() < platform->getY() + 5.0f)
            {
                if (platform->getX() < m_player->getX() && m_player->getX() < platform->getX() + platform->getWidth()) return true;
                else if (platform->getX() < m_player->getX() + m_player->getWidth() && m_player->getX() + m_player->getWidth() < platform->getX() + platform->getWidth()) return true;
            }
        }
        return false;
    }


}