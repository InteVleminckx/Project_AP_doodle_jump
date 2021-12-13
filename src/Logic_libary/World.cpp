#include "World.h"

namespace logic {


    World::World() {

    }

    void World::createPlayer(shared_ptr<EntityFactory> &factory)
    {
        m_player = std::make_shared<logic::Player_L> (0.5f, -1.f, .1f, .125f);
        factory->createPlayer(m_player);
        m_player->jump();
    }

    void World::createPlatform(shared_ptr<EntityFactory> &factory, float y)
    {
        shared_ptr<logic::Subject> platform;

        _Platform type  = Random::Instance()->getPlatformType();

        //TODO: de posities moeten hier nog random gemaakt worden

        switch (type) {
            case Static:
                platform = make_shared<logic::Platform_L_static>(0.5f, y, .15f, .035f);
                break;
            case Horizontal:
                 platform = std::make_shared<logic::Platform_L_horizontal> (0.5f, y, .15f, .035f);
                break;
            case Vertical:
                platform = std::make_shared<logic::Platform_L_vertical> (0.5f, y, .15f, .035f);
                break;
            case Temporary:
                platform = std::make_shared<logic::Platform_L_temporary> (0.5f, y, .15f, .035f);
        }
        factory->createPlatform(platform, type);
        m_platforms.push_back(platform);
    }

    void World::createBonus(shared_ptr<EntityFactory> &factory)
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

        m_player->gravity();
        if (playerTouchesPlatform()) m_player->jump();
        m_player->Notify();

        logic::Camera::Instance()->projectToPixel(m_player->getX(), m_player->getY());

        for (const auto& entity : m_BGtiles) entity->Notify();
        for (const auto& entity : m_platforms)
        {
            entity->movePlatform();
            entity->Notify();
        }
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

        if (m_player->getVelocityY() > 0) return false;

        vector<pair<float, float>> leftPlayer, rightPlayer;
        getPointsBetweenFrames(leftPlayer, rightPlayer, m_player);

        for (auto &platform : m_platforms) {
            for (int i = 0; i < leftPlayer.size(); i++) {
                float platform_Y0 = platform->getY();
                float platform_Y1 = platform->getY() + platform->getHeight();

                //static, controller of de y-waarde van de player tussen het platform ligt
                if (platform_Y0 <= leftPlayer[i].second && leftPlayer[i].second <= platform_Y1) {
                    float platform_X0 = platform->getX();
                    float platform_X1 = platform->getX() + platform->getWidth();
                    // nu nog controlleren of de x-waarde ertussen zit zodat de player effectief het platform geraakt heeft
                    if ((platform_X0 <= leftPlayer[i].first && leftPlayer[i].first <= platform_X1) || (platform_X0 <= rightPlayer[i].first && rightPlayer[i].first <= platform_X1)) {
                        if (platform->isTemporary())removePlatform(platform);
                        return true;
                    }
                }
            }
        }

        return false;
    }

    void World::getPointsBetweenFrames(vector<pair<float, float>> &left, vector<pair<float, float>> &right, const shared_ptr<Subject>& subject) {

        //TODO: reference naar Computer graphics neerzetten

        float x0 = subject->getXprev();
        float x1 = subject->getX();
        float y0 = subject->getYprev();
        float y1 = subject->getY();

        float iterator = 0.001f;

        if (x0 == x1) {
            for (float i = std::min(y0, y1); i <= std::max(y0, y1); i+=iterator) {
                left.emplace_back(x0, i);
                right.emplace_back(x0+m_player->getWidth(), i);
            }
        }
        else if (y0 == y1) {
            for (float i = std::min(x0, x1); i <= std::max(x0, x1); i+=iterator) {
                left.emplace_back(i, y0);
                right.emplace_back(i+m_player->getWidth(), y0);
            }
        }
        else {
            if (x0 > x1) {
                std::swap(x0, x1);
                std::swap(y0, y1);
            }

            float m = ( y1 - y0) / ( x1 - x0);
            if (-1.0 <= m && m <= 1.0) {
                for (float i = 0; i <= (x1 - x0); i+=iterator) {
                    left.emplace_back(x0 + i,  (y0 + m * i));
                    right.emplace_back(x0 + i + m_player->getWidth(),  (y0 + m * i));
                }
            }
            else if (m > 1.0) {
                for (float i = 0; i <= (y1 - y0); i+=iterator) {
                    left.emplace_back( (x0 + (i / m)), y0 + i);
                    right.emplace_back( ((x0 + m_player->getWidth() )+ (i / m)), y0 + i);
                }
            }
            else if (m < -1.0) {
                for (float i = 0; i <= (y0 - y1); i+=iterator) {
                    left.emplace_back( (x0 - (i / m)), y0 - i);
                    right.emplace_back( ((x0 + m_player->getWidth()) - (i / m)), y0 - i);
                }
            }
        }
    }

    void World::removePlatform(shared_ptr<Subject>& platform) {

        for (int i = 0; i<m_platforms.size(); i++) {
            if (platform == m_platforms[i])
            {
                m_platforms.erase(m_platforms.begin() + i);
                break;
            }
        }

    }
}