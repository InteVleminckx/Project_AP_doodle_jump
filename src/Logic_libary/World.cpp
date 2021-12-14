#include "World.h"

namespace logic {


    World::World() {
        leftLogicX = 0;
        rightLogicX = 1.f;
        belowLogicY = -1.f;
    }

    void World::createPlayer(shared_ptr<EntityFactory> &factory, float width, float height)
    {
        m_player = std::make_shared<logic::Player_L> (leftLogicX/2, belowLogicY, width, height);
        factory->createPlayer(m_player);
        m_player->jump();
    }

    void World::createPlatform(shared_ptr<EntityFactory> &factory, float x, float y, float width, float height)
    {
        shared_ptr<logic::Platform_L> platform;

        _Platform type  = Random::Instance()->getPlatformType();

        switch (type) {
            case Static:
                platform = make_shared<logic::Platform_L_static>(x, y, width, height);
                break;
            case Horizontal:
                 platform = std::make_shared<logic::Platform_L_horizontal> (x, y, width, height);
                break;
            case Vertical:
                platform = std::make_shared<logic::Platform_L_vertical> (x, y, width, height);
                break;
            case Temporary:
                platform = std::make_shared<logic::Platform_L_temporary> (x, y, width,height);
        }
        factory->createPlatform(platform, type);
        m_platforms.push_back(platform);
    }

    void World::createBonus(shared_ptr<EntityFactory> &factory, float width, float height)
    {
        shared_ptr<logic::Bonus_L> bonus;
        _Bonus type  = Random::Instance()->getBonusType();

        //TODO: de posities moeten hier nog random gemaakt worden

        switch (type) {
            case Spring:
                bonus = make_shared<logic::Spring_L>(0.5f, 0.f, width, height);
                break;
            case Rocket:
                bonus = std::make_shared<logic::Rocket_L> (0.5f, 0.f, width, height);
        }

        factory->createBonus(bonus, type);
        m_bonussen.push_back(bonus);
    }

    void World::createBG_Tile(shared_ptr<EntityFactory> &factory, float width, float height)
    {
        shared_ptr<logic::BG_Tile_L> tile = std::make_shared<logic::BG_Tile_L> ();
        factory->createBG_Tile(tile);
        m_BGtiles.push_back(tile);
    }

    void World::updateEntities() {

        m_player->gravity();
        if (playerTouchesPlatform()) m_player->jump();
        m_player->Notify();

        logic::Camera::Instance()->projectToPixel(m_player->getX(), m_player->getY());

        for (const auto& entity : m_BGtiles) entity->Notify();

        cout << m_platforms.size() << endl;

        bool removedPlatform = true;
        while(removedPlatform)
        {
            removedPlatform = false;
            for (auto& entity : m_platforms)
            {
                entity->movePlatform();

                if (entity->getY() < m_player->getY() - abs(belowLogicY * 2)){
                    removePlatform(entity);
                    removedPlatform = true;
                    break;
                }

                entity->Notify();
            }
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

    void World::getPointsBetweenFrames(vector<pair<float, float>> &left, vector<pair<float, float>> &right, const shared_ptr<Player_L>& subject) {

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

    void World::removePlatform(shared_ptr<Platform_L>& platform) {

        for (int i = 0; i<m_platforms.size(); i++) {
            if (platform == m_platforms[i])
            {
                m_platforms.erase(m_platforms.begin() + i);
                break;
            }
        }

    }

    void World::createAplatform(float width, float height, shared_ptr<EntityFactory> &factory, bool begin) {
        //We controlleren of er een nieuw platform moet gemaakt worden.
        //op elke lijn staat er eigl maximaal 1 platform
        //We kijken dus of binnen een range van de player of er op een lijn een platform gegenereerd moet worden.

        if (begin)
        {
            renderTop = belowLogicY + (abs(belowLogicY) * 2);

            int aantalPlatforms = ceil((abs(belowLogicY) * 2)/(height*3.5));

            for (int i = 0; i < aantalPlatforms+1; ++i)
            {
                if (Random::Instance()->createPlatform())
                {
                    float y = belowLogicY + (i * height * 3.5);
                    float x = Random::Instance()->giveRandomX(leftLogicX, rightLogicX);

                    if (x > rightLogicX - width) x = rightLogicX - width;

                    createPlatform(factory, x, y, width, height);
                }
            }

        }

        else{

            //TODO: fiks dit nog blijft maar platformen aanmaken.
            if (m_player->getHeight() + renderTop >= renderTop + height)
            {

                renderTop = m_player->getHeight() + renderTop;

                if (Random::Instance()->createPlatform())
                {
                    float x = Random::Instance()->giveRandomX(leftLogicX, rightLogicX);

                    if (x > rightLogicX - width) x = rightLogicX - width;

                    createPlatform(factory, x, renderTop, width, height);
                }
            }

        }

    }
}