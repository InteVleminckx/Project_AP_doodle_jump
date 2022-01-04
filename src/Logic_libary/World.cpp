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

        readSavedScoreFile();

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
    }

    void World::releaseObservers() {

        ControllingPointers::control(m_player, "World", "releaseObservers()");
        m_player->emptyObserver();

        for (const auto& entity : m_BGtiles)
        {
            ControllingPointers::control(entity, "World", "releaseObservers()");
            entity->emptyObserver();
        }
        for (const auto& entity : m_platforms) {
            ControllingPointers::control(entity, "World", "releaseObservers()");
            entity->emptyObserver();
        }
        for (const auto& entity : m_bonussen) {
            ControllingPointers::control(entity, "World", "releaseObservers()");
            entity->emptyObserver();
        }

        m_BGtiles.clear();
        m_platforms.clear();
        m_bonussen.clear();

    }

    template<class A, class B>
    bool World::Collision(vector<pair<float, float>> &movedSubjectpath, const shared_ptr<A>& movedSubject, const shared_ptr<B>& subject, bool goesUp) {
        ControllingPointers::control(subject, "World", "Collision(vector<pair<float, float>> &leftPlayer, vector<pair<float, float>> &rightPlayer, const shared_ptr<T>& subject)");

        for (int i = 0; i < movedSubjectpath.size(); i++) {
            float subject_Y0 = subject->getY();
            float subject_Y1 = subject->getY() + subject->getHeight();

            float movedSubject_y = movedSubjectpath[i].second;
            if (goesUp) movedSubject_y += movedSubject->getHeight();

            if (subject_Y0 <= movedSubject_y && movedSubject_y <= subject_Y1) {
                float smallest_X0, smallest_X1, biggest_X0, biggest_X1 ;

                if (subject->getWidth() < movedSubject->getWidth()) {
                    smallest_X0 = subject->getX();
                    smallest_X1 = subject->getX() + subject->getWidth();

                    biggest_X0 = movedSubject->getX();
                    biggest_X1 = movedSubject->getX() + movedSubject->getWidth();
                }

                else {
                    biggest_X0 = subject->getX();
                    biggest_X1 = subject->getX() + subject->getWidth();
                    smallest_X0 = movedSubject->getX();
                    smallest_X1 = movedSubject->getX() + movedSubject->getWidth();
                }

                if ((biggest_X0 <= smallest_X0 && smallest_X0 <= biggest_X1) || (biggest_X0 <= smallest_X1 && smallest_X1 <= biggest_X1)) {
                    return true;
                }
            }

        }

        return false;
    }

    template<class T>
    void World::getPointsBetweenFrames(vector<pair<float, float>> &left, const shared_ptr<T>& subject) {

        ControllingPointers::control(subject, "World", "getPointsBetweenFrames(vector<pair<float, float>> &left, vector<pair<float, float>> &right, const shared_ptr<Player_L>& subject)");

        //Code gehaald uit project van vorig jaar voor het Project Computer Graphics.

        float x0 = subject->getXprev();
        float x1 = subject->getX();
        float y0 = subject->getYprev();
        float y1 = subject->getY();

        float iterator = 0.001f;

        if (x0 == x1) {
            for (float i = std::min(y0, y1); i <= std::max(y0, y1); i+=iterator) {
                left.emplace_back(x0, i);
            }
        }
        else if (y0 == y1) {
            for (float i = std::min(x0, x1); i <= std::max(x0, x1); i+=iterator) {
                left.emplace_back(i, y0);
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
                }
            }
            else if (m > 1.0) {
                for (float i = 0; i <= (y1 - y0); i+=iterator) {
                    left.emplace_back( (x0 + (i / m)), y0 + i);
                }
            }
            else if (m < -1.0) {
                for (float i = 0; i <= (y0 - y1); i+=iterator) {
                    left.emplace_back( (x0 - (i / m)), y0 - i);
                }
            }
        }
    }

    void World::changeGameStatus() {
        if (m_isGamePlaying) m_isGamePlaying = false;
        else m_isGamePlaying = true;

    }

    bool World::checkOutOfScope(const shared_ptr<EntityModel>& model) {
        ControllingPointers::control(model, "World", "checkOutOfScope(const shared_ptr<EntityModel>& model)");
        ControllingPointers::control(m_player, "World", "checkOutOfScope(const shared_ptr<EntityModel>& model)");

        if (model->getY()+model->getHeight() < m_player->getY() - abs(m_belowLogicY)){
            return true;
        }

        return false;
    }

    template<class T> void World::NotifyAll(vector<shared_ptr<T>>& models){
        //controlen voor type
        if (is_same<T, Player_L>::value || is_same<T, Platform_L>::value ||
                is_same<T, BG_Tile_L>::value || is_same<T, Bonus_L>::value)
        {
            for (auto& model: models) {model->Notify();}
        }

    }

    /*BEGIN**************************************** Player ****************************************BEGIN*/

    void World::createPlayer(shared_ptr<EntityFactory> &factory)
    {

        m_player = move(std::make_shared<logic::Player_L> ((m_leftLogicX + m_rightLogicX) / 2, m_belowLogicY + m_playerHeight, m_playerWidth, m_playerHeight));

        ControllingPointers::control(factory, "World", "createPlayer(shared_ptr<EntityFactory> &factory)");
        ControllingPointers::control(m_player, "World", "createPlayer(shared_ptr<EntityFactory> &factory)");

        factory->createPlayer(m_player);
        m_player->Notify();
        m_player->jump();
    }

    void World::refreshPlayer() {
        ControllingPointers::control(m_player, "World", "refreshPlayer()");

        //Controleren eerst of de speler links of rechts wilt bewegen.
        if (representation::Window::Instance()->isPressedLeft()) movePlayerLeft();
        if (representation::Window::Instance()->isPressedRight()) movePlayerRight();

        //Passen de zwaartekracht toe op de speler.
        m_player->gravity();
        if (logic::Camera::Instance()->setOffset(m_player->getY())){
            NotifyAll(m_platforms);
            NotifyAll(m_bonussen);
        }

        //Controleren op een collision.
        playerCollision();

        //Controleert of de speler uit het scherm is van onder, zoja eindigt het spel.
        playerOutOfScope();
    }

    void World::movePlayerRight() {
        ControllingPointers::control(m_player, "World", "movePlayerRight()");

        m_player->moveRight(m_leftLogicX, m_rightLogicX);
    }

    void World::movePlayerLeft() {
        ControllingPointers::control(m_player, "World", "movePlayerRight()");

        m_player->moveLeft(m_leftLogicX, m_rightLogicX);
    }

    void World::playerTouchesPlatform(vector<pair<float, float>>& playerPath) {
        ControllingPointers::control(m_player, "World", "playerTouchesPlatform(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer)");

        if (m_player->getVelocityY() > 0) return;

        for (auto &platform : m_platforms) {

            ControllingPointers::control(platform, "World", "playerTouchesPlatform(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer)");

            if (Collision(playerPath, m_player, platform)){
                m_player->jump();
                if (platform->isJumpedOn()) {
                    m_score->addNegativePoints(platform->getDecreasingValue());
                }
                else {
                    platform->setJumpedOn();
                }
                if (platform->isTemporary()) {removePlatform(platform);}
                return;

            }
        }
    }

    void World::playerTouchesBoost(vector<pair<float, float>>& playerPath) {
        ControllingPointers::control(m_player, "World", "playerTouchesBoost(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer)");

        for (auto &bonus : m_bonussen) {
            ControllingPointers::control(bonus, "World", "playerTouchesBoost(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer)");

            if (Collision(playerPath, m_player, bonus)){
                if (bonus->getInvolmsVelocity() && m_player->getVelocityY() <= 0 && !m_player->getBonusActive())
                {
                    m_player->powerup(bonus->getForce());
                    m_score->addPositivesPoints(bonus->getIncreasingValue());
                }
                else if (! bonus->getInvolmsVelocity() && !m_player->getBonusActive()){
                    m_player->powerup(bonus->getForce());
                    m_score->addPositivesPoints(bonus->getIncreasingValue());
                }
            }
        }
    }

    void World::playerCollision() {
        vector<pair<float, float>> leftPlayer;
        getPointsBetweenFrames(leftPlayer, m_player);
        playerTouchesBoost(leftPlayer);
        playerTouchesPlatform(leftPlayer);

    }

    void World::playerOutOfScope() {
        ControllingPointers::control(m_player, "World", "playerOutOfScope()");

        if (m_player->getY() < Camera::Instance()->getOffset() - abs(m_belowLogicY) ) m_isGamePlaying = false;
    }

    /*END****************************************** Player ******************************************END*/

    /*BEGIN*************************************** Platform ***************************************BEGIN*/

    void World::createPlatform(shared_ptr<EntityFactory> &factory, float x, float y){
        ControllingPointers::control(factory, "World", "createPlatform(shared_ptr<EntityFactory> &factory, float x, float y)");


        shared_ptr<logic::Platform_L> platform;

        PlatformType type  = Random::Instance()->getPlatformType();

        switch (type) {
            case Static_:
                if (Random::Instance()->createBonus()) createBonus(factory, x, y);
                platform = move(make_shared<logic::Platform_L_static>(x, y, m_platformWidth, m_platformHeight));
                break;
            case Horizontal_:
                platform = move(make_shared<logic::Platform_L_horizontal> (x, y, m_platformWidth, m_platformHeight));
                break;
            case Vertical_:
                platform = move(make_shared<logic::Platform_L_vertical> (x, y, m_platformWidth, m_platformHeight));
                break;
            case Temporary_:
                platform = move(make_shared<logic::Platform_L_temporary> (x, y, m_platformWidth,m_platformHeight));
        }
        factory->createPlatform(platform, type);
        platform->Notify();
        m_platforms.push_back(move(platform));
    }

    void World::refreshPlatform() {

        //we gaan ook eerst nog controleren of er een platform aangemaakt moet worden.
        createAplatform(m_entityFactory);
        platformTouchesPlatform();

        bool removedPlatform = true;

        //telkens als er een platform verwijderd wordt, wordt de lijst van platforms aangepast.
        //Daarom gaan we als we een platform verwijderen de while loop onderbreken en terug opnieuw beginnen.
        //Zolang er een platform verwijderd wordt.

        while(removedPlatform)
        {
            removedPlatform = false;
            for (auto& entity : m_platforms)
            {
                ControllingPointers::control(entity, "World", "refreshPlatform()");

                entity->movePlatform();
                if (checkOutOfScope(entity)){
                    removePlatform(entity);
                    removedPlatform = true;
                    break;
                }
            }
        }
    }

    void World::createAplatform(shared_ptr<EntityFactory> &factory, bool begin) {

        ControllingPointers::control(factory, "World", "createAplatform(shared_ptr<EntityFactory> &factory, bool begin)");
        ControllingPointers::control(m_player, "World", "createAplatform(shared_ptr<EntityFactory> &factory, bool begin)");


        //We controlleren of er een nieuw platform moet gemaakt worden.
        //op elke lijn staat er eigl maximaal 1 platform
        //We kijken dus of binnen een range van de player of er op een lijn een platform gegenereerd moet worden.

        if (begin)
        {
            m_renderTop = m_belowLogicY + (abs(m_belowLogicY) * 2);

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
            if (m_player->getY() + (abs(m_belowLogicY) * 2) > m_renderTop + (m_platformHeight * 2.5))
            {
                m_renderTop = m_player->getY() + (abs(m_belowLogicY) * 2);
                if (Random::Instance()->createPlatform(m_prevPlatform, m_renderTop))
                {
                    float x = Random::Instance()->giveRandomX(m_leftLogicX, m_rightLogicX);
                    if (x > m_rightLogicX - m_platformWidth) x = m_rightLogicX - m_platformWidth;
                    createPlatform(factory, x, m_renderTop);
                    m_prevPlatform = m_renderTop;
                }
            }

        }

    }

    void World::removePlatform(shared_ptr<Platform_L>& platform) {
        ControllingPointers::control(platform, "World", "removePlatform(shared_ptr<Platform_L>& platform)");

        for (int i = 0; i<m_platforms.size(); i++) {
            if (platform == m_platforms[i])
            {
                platform->emptyObserver();
                m_platforms.erase(m_platforms.begin() + i);
                break;
            }
        }

    }

    void World::platformTouchesPlatform() {

        for (const auto &platform1 : m_platforms) {

            vector<pair<float, float>> path;
            getPointsBetweenFrames(path, platform1);
            bool up = false;
            if (platform1->getVelocityY() < 0) up = true;

            for (const auto &platform2 : m_platforms) {

                if (platform1 == platform2) continue;
                if (Collision(path, platform1, platform2, up)){
                    platform1->changeDirection();
                    break;
                }

            }
        }
    }

    /*END***************************************** Platform *****************************************END*/

    /*BEGIN**************************************** Score *****************************************BEGIN*/

    void World::createScore(shared_ptr<EntityFactory> &factory) {
        ControllingPointers::control(factory, "World", "createScore(shared_ptr<EntityFactory> &factory)");

        factory->createScore(m_player, m_score);
    }

    int World::getHighScore() {
        return m_highScore;
    }

    void World::readSavedScoreFile() {
        string pathSavedFile = "../Save/highscore.json";

        ifstream highscoreJSONFile(pathSavedFile);
        json highScoreJson;

        ofstream newHighscoreFile;

        try {
            if(!highscoreJSONFile){
                throw InputSaveFileException();
            }
        }
        catch (InputSaveFileException& exception){
            cout << exception.what() << pathSavedFile << endl;
            cout << "File highscore.json wordt aangemaakt in de directory Save" << endl;
            newHighscoreFile.open("../Save/highscore.json");
            highScoreJson["highscore"] = 0;
            highScoreJson["score"] = 0;
            newHighscoreFile << highScoreJson << endl;
            newHighscoreFile.close();
            highscoreJSONFile.open(pathSavedFile);
        }

        highscoreJSONFile >> highScoreJson;

        m_prevScore = highScoreJson["score"];
        m_highScore = highScoreJson["highscore"];

    }

    int World::getScore() {
        return m_prevScore;
    }

    void World::saveScore() {
        string pathSavedFile = "../Save/highscore.json";
        ifstream highscoreJSONFile(pathSavedFile);
        json highScoreJson;
        ofstream newHighscoreFile;

        try {
            if(!highscoreJSONFile){
                throw InputSaveFileException();
            }
        }
        catch (InputSaveFileException& exception){
            cout << exception.what() << pathSavedFile << endl;
        }

        highscoreJSONFile >> highScoreJson;

        int highscore = highScoreJson["highscore"];

        highScoreJson["score"] = m_score->getRecalculatedScore();
        if (m_score->getRecalculatedScore() > highscore) highScoreJson["highscore"] = m_score->getRecalculatedScore();
        else  highScoreJson["highscore"] = highscore;
        newHighscoreFile.clear();
        newHighscoreFile.open(pathSavedFile);
        newHighscoreFile << highScoreJson << endl;
    }

    /*END****************************************** Score *******************************************END*/


    /*BEGIN*************************************** bg_tile ****************************************BEGIN*/

    void World::createBG_Tile(shared_ptr<EntityFactory> &factory, bool second)
    {
        ControllingPointers::control(factory, "World", "createBG_Tile(shared_ptr<EntityFactory> &factory, bool second)");

        shared_ptr<logic::BG_Tile_L> tile;
        if (second) {
            tile = move(std::make_shared<logic::BG_Tile_L>(m_leftLogicX, (abs(m_belowLogicY) * 2) - abs(m_belowLogicY), m_bgTileWidth, m_bgTileHeight));
        }
        else {
            tile = move(std::make_shared<logic::BG_Tile_L>(m_leftLogicX, m_belowLogicY, m_bgTileWidth, m_bgTileHeight));
        }
        factory->createBG_Tile(tile);
        tile->Notify();
        m_BGtiles.push_back(move(tile));
    }

    void World::refreshBg_Tile() {
        tileOutOfView();

    }

    void World::tileOutOfView() {

        for (auto& tile : m_BGtiles){
            ControllingPointers::control(tile, "World", "tileOutOfView()");

            if (tile->getY() + tile->getHeight() <= m_player->getY() - (abs(m_belowLogicY) * 2))
            {
                tile->setY(tile->getY() + (2*m_bgTileHeight));
            }
        }
    }

    /*END***************************************** bg_tile ******************************************END*/

    /*BEGIN**************************************** Bonus *****************************************BEGIN*/

    void World::createBonus(shared_ptr<EntityFactory> &factory, float x, float y)
    {
        ControllingPointers::control(factory, "World", "createBonus(shared_ptr<EntityFactory> &factory, float x, float y)");

        shared_ptr<logic::Bonus_L> bonus;
        BonusType type  = Random::Instance()->getBonusType();
        float x1;

        switch (type) {
            case Spring_:
                x1 = x + (m_platformWidth/2) - (m_springWidth/2);
                bonus = move(make_shared<logic::Spring_L>(x1, y+m_platformHeight, m_springWidth, m_springHeight));
                break;
            case Rocket_:
                x1 = x + (m_platformWidth/2) - (m_rocketWidth/2);
                bonus = move(std::make_shared<logic::Rocket_L> (x1, y+m_platformHeight, m_rocketWidth, m_rocketHeight));
        }

        factory->createBonus(bonus, type);
        bonus->Notify();
        m_bonussen.push_back(move(bonus));

    }

    void World::refreshBonus() {

        bool removedBonus = true;

        //telkens als er een bonus verwijderd wordt, wordt de lijst van bonussen aangepast.
        //Daarom gaan we als we een bonus verwijderen de while loop onderbreken en terug opnieuw beginnen.
        //Zolang er een bonus verwijderd wordt.

        while(removedBonus)
        {
            removedBonus = false;
            for (auto& entity : m_bonussen)
            {
                ControllingPointers::control(entity, "World", "refreshBonus()");

                if (checkOutOfScope(entity)){
                    removeBonus(entity);
                    removedBonus = true;
                    break;
                }
            }
        }
    }

    void World::removeBonus(shared_ptr<Bonus_L>& bonus) {
        ControllingPointers::control(bonus, "World", "removeBonus(shared_ptr<Bonus_L>& bonus)");

        for (int i = 0; i<m_bonussen.size(); i++) {
            if (bonus == m_bonussen[i])
            {
                bonus->emptyObserver();
                m_bonussen.erase(m_bonussen.begin() + i);
                break;
            }
        }
    }

    /*END****************************************** Bonus *******************************************END*/

    World::~World() = default;

}