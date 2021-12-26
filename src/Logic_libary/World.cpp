#include "World.h"

namespace logic {


    World::World() {
        m_leftLogicX = 0;
        m_rightLogicX = 1.f;
        m_belowLogicY = -1.f;

        m_playerHeight = .125f; m_playerWidth = .1f;
        m_platformHeight = 0.035f; m_platformWidth = .15f;
        m_springHeight = .05f; m_springWidth = .05f;
        m_rocketHeight = .075f; m_rocketWidth = .075f;
        m_bgTileHeight = abs(m_belowLogicY) * 3; m_bgTileWidth = abs(m_leftLogicX) + abs(m_rightLogicX);

        m_isGamePlaying = false;


    }

    void World::setFactory(shared_ptr<EntityFactory> &factory) {
        m_entityFactory = move(factory);
    }

    void World::setupWorld() {

        //In het logic gedeelte hebben we enkel de stopwatch en random nodig
        //om het spel zijn functionaliteit te gevev.
        logic::Stopwatch::Instance();
        logic::Random::Instance();

        createPlayer(m_entityFactory);

        createAplatform(m_entityFactory, true);

        createScore(m_entityFactory);

        createBG_Tile(m_entityFactory, false);
        createBG_Tile(m_entityFactory, true);
    }

    bool World::getGameStatus() {
        return m_isGamePlaying;
    }

    void World::updateWorld() {

        refreshBg_Tile();
        refreshPlayer();
        refreshPlatform();
        refreshBonus();

        //Als alle entities zijn gerefreshed resetten we de clock.
        logic::Stopwatch::Instance()->Reset();

        //Veranderd de moeilijkheidsgraad als dit nodig is.
        logic::Random::Instance()->refreshDifficulty(logic::Camera::Instance()->reproduceScore(m_score->getScore()));
    }

    void World::releaseObservers() {
        m_player->emptyObserver();
        for (const auto& entity : m_BGtiles) entity->emptyObserver();
        for (const auto& entity : m_platforms) entity->emptyObserver();
        for (const auto& entity : m_bonussen) entity->emptyObserver();
    }

    void World::getPointsBetweenFrames(vector<pair<float, float>> &left, vector<pair<float, float>> &right, const shared_ptr<Player_L>& subject) {


        //Code gehaald uit project van vorig jaar voor het Project Computer Graphics.

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

    void World::changeGameStatus() {
        if (m_isGamePlaying) m_isGamePlaying = false;
        else m_isGamePlaying = true;

    }

    /*BEGIN**************************************** Player ****************************************BEGIN*/

    void World::createPlayer(shared_ptr<EntityFactory> &factory)
    {
        m_player = std::make_shared<logic::Player_L> ((m_leftLogicX + m_rightLogicX) / 2, m_belowLogicY + m_playerHeight, m_playerWidth, m_playerHeight);
        factory->createPlayer(m_player);
        m_player->jump();
    }

    void World::refreshPlayer() {

        //Controleren eerst of de speler links of rechts wilt bewegen.
        if (representation::Window::Instance()->isPressedLeft()) movePlayerLeft();
        if (representation::Window::Instance()->isPressedRight()) movePlayerRight();

        //Passen de zwaartekracht toe op de speler.
        m_player->gravity();

        //Controleren op een collision.
        playerCollision();

        //Controleert of de speler uit het scherm is van onder, zoja eindigt het spel.
        playerOutOfScope();

        m_player->Notify();
    }

    void World::movePlayerRight() {
        m_player->moveRight(m_leftLogicX, m_rightLogicX);
    }

    void World::movePlayerLeft() {
        m_player->moveLeft(m_leftLogicX, m_rightLogicX);
    }

    void World::playerTouchesPlatform(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer) {

        if (m_player->getVelocityY() > 0) return;

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
                        m_player->jump();
                        if (platform->isTemporary()) {removePlatform(platform);}
                        return;
                    }
                }
            }
        }
    }

    void World::playerTouchesBoost(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer) {

        for (auto &bonus : m_bonussen) {
            for (int i = 0; i < leftPlayer.size(); i++) {
                float bonus_Y0 = bonus->getY();
                float bonus_Y1 = bonus->getY() + bonus->getHeight();

                if (bonus_Y0 <= leftPlayer[i].second && leftPlayer[i].second <= bonus_Y1) {
                    float bonus_X0 = bonus->getX();
                    float bonus_X1 = bonus->getX() + bonus->getWidth();

                    if (( leftPlayer[i].first <= bonus_X0  && bonus_X0 <=  rightPlayer[i].first) || ( leftPlayer[i].first <= bonus_X1  && bonus_X1 <=  rightPlayer[i].first)) {

                        if (bonus->getInvolmsVelocity() && m_player->getVelocityY() <= 0)
                        {
                            m_player->powerup(bonus->getForce());
                        }
                        else if (! bonus->getInvolmsVelocity()){
                            m_player->powerup(bonus->getForce());
                        }

                    }
                }
            }
        }
    }

    /*END***************************************** bg_tile ******************************************END*/

    void World::playerCollision() {
        vector<pair<float, float>> leftPlayer, rightPlayer;
        getPointsBetweenFrames(leftPlayer, rightPlayer, m_player);
        playerTouchesBoost(leftPlayer, rightPlayer);
        playerTouchesPlatform(leftPlayer, rightPlayer);

    }

    void World::playerOutOfScope() {
        if (m_player->getY() < Camera::Instance()->getOffset() - abs(m_belowLogicY) ) m_isGamePlaying = false;
    }

    /*END****************************************** Player ******************************************END*/

    /*BEGIN*************************************** Platform ***************************************BEGIN*/

    void World::createPlatform(shared_ptr<EntityFactory> &factory, float x, float y)
    {
        shared_ptr<logic::Platform_L> platform;

        PlatformType type  = Random::Instance()->getPlatformType();

        switch (type) {
            case Static_:
                if (Random::Instance()->createBonus()) createBonus(factory, x, y);
                platform = make_shared<logic::Platform_L_static>(x, y, m_platformWidth, m_platformHeight);
                break;
            case Horizontal_:
                platform = std::make_shared<logic::Platform_L_horizontal> (x, y, m_platformWidth, m_platformHeight);
                break;
            case Vertical_:
                platform = std::make_shared<logic::Platform_L_vertical> (x, y, m_platformWidth, m_platformHeight);
                break;
            case Temporary_:
                platform = std::make_shared<logic::Platform_L_temporary> (x, y, m_platformWidth,m_platformHeight);
        }
        factory->createPlatform(platform, type);
        m_platforms.push_back(platform);
    }

    void World::refreshPlatform() {

        //we gaan ook eerst nog controleren of er een platform aangemaakt moet worden.
        createAplatform(m_entityFactory);

        bool removedPlatform = true;

        //telkens als er een platform verwijderd wordt, wordt de lijst van platforms aangepast.
        //Daarom gaan we als we een platform verwijderen de while loop onderbreken en terug opnieuw beginnen.
        //Zolang er een platform verwijderd wordt.

        while(removedPlatform)
        {
            removedPlatform = false;
            for (auto& entity : m_platforms)
            {
                entity->movePlatform();

                if (entity->getY() < m_player->getY() - abs(m_belowLogicY)){
                    removePlatform(entity);
                    removedPlatform = true;
                    break;
                }
                entity->Notify();
            }

        }
    }

    void World::createAplatform(shared_ptr<EntityFactory> &factory, bool begin) {
        //We controlleren of er een nieuw platform moet gemaakt worden.
        //op elke lijn staat er eigl maximaal 1 platform
        //We kijken dus of binnen een range van de player of er op een lijn een platform gegenereerd moet worden.

        if (begin)
        {
            renderTop = m_belowLogicY + (abs(m_belowLogicY) * 2);

            int aantalPlatforms = ceil((abs(m_belowLogicY) * 2) / (m_platformHeight * 3.5));

            for (int i = 0; i < aantalPlatforms+1; ++i)
            {
                float y = m_belowLogicY + (i * m_platformHeight * 3.5);
                if (Random::Instance()->createPlatform(m_prevPlatform,y))
                {
                    float x = Random::Instance()->giveRandomX(m_leftLogicX, m_rightLogicX);

                    if (x > m_rightLogicX - m_platformWidth) x = m_rightLogicX - m_platformWidth;

                    createPlatform(factory, x, y);
                    m_prevPlatform = y;
                }
            }

        }

        else{
            if (m_player->getY() + (abs(m_belowLogicY) * 2) > renderTop + (m_platformHeight * 2.5))
            {
                renderTop = m_player->getY() + (abs(m_belowLogicY) * 2);
                if (Random::Instance()->createPlatform(m_prevPlatform, renderTop))
                {
                    float x = Random::Instance()->giveRandomX(m_leftLogicX, m_rightLogicX);
                    if (x > m_rightLogicX - m_platformWidth) x = m_rightLogicX - m_platformWidth;
                    createPlatform(factory, x, renderTop);
                    m_prevPlatform = renderTop;
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

    /*END***************************************** Platform *****************************************END*/

    /*BEGIN**************************************** Score *****************************************BEGIN*/

    void World::createScore(shared_ptr<EntityFactory> &factory) {
        factory->createScore(m_player, m_score);

    }

    int World::getScore() {

        if (m_score != nullptr)
        {
            return Camera::Instance()->reproduceScore(m_score->getScore());
        }

        else return 0;

    }

    /*END****************************************** Score *******************************************END*/

    /*BEGIN*************************************** bg_tile ****************************************BEGIN*/

    void World::createBG_Tile(shared_ptr<EntityFactory> &factory, bool second)
    {
        shared_ptr<logic::BG_Tile_L> tile;
        if (second) {
            tile = std::make_shared<logic::BG_Tile_L>(m_leftLogicX, (abs(m_belowLogicY) * 2) - abs(m_belowLogicY), m_bgTileWidth, m_bgTileHeight);
        }
        else {
            tile = std::make_shared<logic::BG_Tile_L>(m_leftLogicX, m_belowLogicY, m_bgTileWidth, m_bgTileHeight);
        }
        factory->createBG_Tile(tile);
        m_BGtiles.push_back(tile);
    }

    void World::refreshBg_Tile() {
        tileOutOfView();
        for (const auto& entity : m_BGtiles) entity->Notify();
    }

    void World::tileOutOfView() {

        for (auto& tile : m_BGtiles){

            if (tile->getY() + tile->getHeight() <= m_player->getY() - (abs(m_belowLogicY) * 2))
            {
                tile->setY(tile->getY() + (2*m_bgTileHeight));
            }
        }
    }

    /*BEGIN**************************************** Bonus *****************************************BEGIN*/

    void World::createBonus(shared_ptr<EntityFactory> &factory, float x, float y)
    {
        shared_ptr<logic::Bonus_L> bonus;
        BonusType type  = Random::Instance()->getBonusType();
        float x1;

        switch (type) {
            case Spring_:
                x1 = x + (m_platformWidth/2) - (m_springWidth/2);
                bonus = make_shared<logic::Spring_L>(x1, y+m_platformHeight, m_springWidth, m_springHeight);
                break;
            case Rocket_:
                x1 = x + (m_platformWidth/2) - (m_rocketWidth/2);
                bonus = std::make_shared<logic::Rocket_L> (x1, y+m_platformHeight, m_rocketWidth, m_rocketHeight);
        }

        factory->createBonus(bonus, type);
        m_bonussen.push_back(bonus);
    }

    void World::refreshBonus() {

        for (const auto& entity : m_bonussen) entity->Notify();
    }

    /*END****************************************** Bonus *******************************************END*/

}