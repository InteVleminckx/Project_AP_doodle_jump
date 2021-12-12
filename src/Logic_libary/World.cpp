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
        else {
        }
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

        for (auto &platform : m_platforms)
        {
            vector<pair<float, float>> leftPlatform, rightPlatfrom;
            getPointsBetweenFrames(leftPlatform, rightPlatfrom, platform);

            for (int i = 0; i < leftPlayer.size(); i++) {

                //static, controller of de y-waarde van de player tussen het platform ligt
                if (leftPlatform.size() == 1 &&
                    leftPlatform[0].second <= leftPlayer[i].second &&
                    leftPlayer[i].second <= leftPlatform[0].second + platform->getHeight() )
                {
                    // nu nog controlleren of de x-waarde ertussen zit zodat de player effectief het platform geraakt heeft
                    float Bx0 = leftPlatform[0].first;
                    float Bx1 = rightPlatfrom[0].first;

//                    cout << endl << m_player->getX() << endl;
//
//                    cout << "PlatformLeft: " << Bx0 << " <= PlayerLeft: " << leftPlayer[i].first << " <= PlatformRight: " << Bx1 << endl;

                    if (Bx0 <= leftPlayer[i].first && leftPlayer[i].first <= Bx1)
                    {
                        if (platform->isTemporary())removePlatform(platform);
                        return true;
                    }

//                    cout << "PlatformLeft: " << Bx0 << " <= PlayerRight: " << rightPlayer[i].first << " <= PlatformRight: " << Bx1 << endl;
                    if (Bx0 <= rightPlayer[i].first && rightPlayer[i].first <= Bx1) {
                        if (platform->isTemporary())removePlatform(platform);
                        return true;
                    }

                }

                //dynamic
                else  {


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