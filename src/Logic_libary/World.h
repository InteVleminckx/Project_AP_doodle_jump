/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class World
 * @BaseClass none
 * @SubClasses none
 * @Namespace logic
 * @brief Is verantwoordelijk voor het orkestreren van de algemene spellogica en de interacties tussen
 * de entiteiten die het bevat, zoals het creëren en vernietigen van entiteiten en collision tussen hen.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_WORLD_H
#define DOODLE_JUMP_WORLD_H

#include <iostream>
#include "Stopwatch.h"
#include "../Game_Representation/ConcreteFactory.h"
#include "Player.h"
#include "Platform.h"
#include "BG_Tile.h"
#include "Bonus.h"
#include "Random.h"
#include <memory>
#include "Camera.h"
#include "Score_L.h"
#include "ControllingPointers.h"

#include <fstream>
#include "../json.hpp"

using json = nlohmann::json;

using namespace std;

namespace logic {

    class World {

        /****************************************************************************************************
         * @brief Een vector van shared_ptr die alle logische bonussen bijhoudt.
         * @type vector<shared_ptr<Bonus_L>>
         * @var m_bonussen
         ****************************************************************************************************/
        vector<shared_ptr<Bonus_L>> m_bonussen;

        /****************************************************************************************************
         * @brief Een vector van shared_ptr die alle logische platforms bijhoudt.
         * @type vector<shared_ptr<Platform_L>>
         * @var m_platforms
         ****************************************************************************************************/
        vector<shared_ptr<Platform_L>> m_platforms;

        /****************************************************************************************************
         * @brief Een vector van shared_ptr die alle logische bg_tiles bijhoudt.
         * @type vector<shared_ptr<BG_Tile_L>>
         * @var m_BGtiles
         ****************************************************************************************************/
        vector<shared_ptr<BG_Tile_L>> m_BGtiles;

        /****************************************************************************************************
         * @brief shared_ptr die de logische speler bijhoudt.
         * @type shared_ptr<Player_L>
         * @var m_player
         ****************************************************************************************************/
        shared_ptr<Player_L> m_player;

        /****************************************************************************************************
         * @brief Zijn de world boundries in het logische coördinaat systeem
         * @type float
         * @var m_leftLogicX, m_rightLogicX, m_belowLogicY
         ****************************************************************************************************/
        float m_leftLogicX{}, m_rightLogicX{}, m_belowLogicY{};

        /****************************************************************************************************
         * @brief Is de plaats waar nieuw een nieuw platform gemaakt moet worden.
         * @type float
         * @var m_renderTop
         ****************************************************************************************************/
        float m_renderTop{};

        /****************************************************************************************************
         * @brief Zijn alle afmetingen voor de entities.
         * @type float
         * @var m_playerHeight, m_playerWidth, m_platformHeight, m_platformWidth, m_springHeight, m_springWidth, m_rocketHeight, m_rocketWidth, m_bgTileHeight, m_bgTileWidth
         ****************************************************************************************************/
        float m_playerHeight{}, m_playerWidth{};
        float m_platformHeight{}, m_platformWidth{};
        float m_springHeight{}, m_springWidth{};
        float m_rocketHeight{}, m_rocketWidth{};
        float m_bgTileHeight{}, m_bgTileWidth{};

        /****************************************************************************************************
        * @brief De y waarde van de laatst gegenereerde y platform
        * @type float
        * @var m_prevPlatform
        ****************************************************************************************************/
        float m_prevPlatform{-1.f};

       /****************************************************************************************************
        * @brief Zegt of de game actief is of niet. Als het false is zitten we in het menu anders in de game.
        * @type bool
        * @var m_isGamePlaying
        ****************************************************************************************************/
        bool m_isGamePlaying;

        /****************************************************************************************************
         * @brief Is de factory waar alle entities ingemaakt worden.
         * @type shared_ptr<EntityFactory>
         * @var m_entityFactory
         ****************************************************************************************************/
        shared_ptr<EntityFactory> m_entityFactory;

        int m_score{};

        int m_highScore{};

    public:

        /****************************************************************************************************
         * @function World()
         * @brief Een constructor waar alle data members worden ingesteld.
         ****************************************************************************************************/
        World();

        /****************************************************************************************************
         * @function setFactory()
         * @brief Initialiseerd de factory voor de world class.
         * @param factory Is een shared pointer van een EntityFactory.
         ****************************************************************************************************/
        void setFactory(shared_ptr<EntityFactory>& factory);

        /****************************************************************************************************
         * @function setupWorld()
         * @brief Alle nodig entities die in het begin nodig zijn worden hier aangemaakt.
         ****************************************************************************************************/
        void setupWorld();

        /****************************************************************************************************
         * @function bool getGameStatus()
         * @brief Geeft de status van de game terug als een boolean.
         * @return Een boolean wat de gamestatus voorstelt.
         ****************************************************************************************************/
        bool getGameStatus();

        /****************************************************************************************************
         * @function void updateWorld()
         * @brief Zorgt dat alles in de wereld wordt geupdate. En roept hun notify functies aan.
         ****************************************************************************************************/
        void updateWorld();

        /****************************************************************************************************
         * @function void releaseObservers()
         * @brief Maakt de vectors van alle entities leeg zodat er geen memory leaks onstaan. En als we een nieuw spel willen starten.
         ****************************************************************************************************/
        void releaseObservers();

        /****************************************************************************************************
         * @function void getPointsBetweenFrames(vector<pair<float, float>>& left, vector<pair<float, float>>& right, const shared_ptr<Player_L>& subject)
         * @brief Trekt een lijn tussen de player zijn coördinaten tussen de huidige frame en de vorige frame.
         * @param left: Een vector<pair<float, float>>& left waar de linkerlijn in komt wat het pad is dat de player met zijn
         * uiterste linkse kant heeft afgelegd.
         * @param right: Een vector<pair<float, float>>& right waar de rechterlijn in komt wat het pad is dat de player met zijn
         * uiterste rechtse kant heeft afgelegd.
         * @param player: Een const shared_ptr<Player_L> is de speler waar de lijnen van gemaakt moeten worden.
         ****************************************************************************************************/
        void getPointsBetweenFrames(vector<pair<float, float>>& left, vector<pair<float, float>>& right, const shared_ptr<Player_L>& player);

        /****************************************************************************************************
        * @function void changeGameStatus()
        * @brief Past de gamestatus aan naar het tegenovergestelde dat het al is.
        ****************************************************************************************************/
        void changeGameStatus();

        /****************************************************************************************************
        * @function bool checkOutOfScope(const shared_ptr<EntityModel>& model)
        * @brief Kijkt of een entity out of view is, zoja wordt true gereturned.
        * @param model:  const shared_ptr<EntityModel>& de entity die gecontroleert wordt.
        * @return boolean wat zegt of de entity out of scope is of niet.
        ****************************************************************************************************/
        bool checkOutOfScope(const shared_ptr<EntityModel>& model);

        /*BEGIN**************************************** Player ****************************************BEGIN*/

        /****************************************************************************************************
         * @function void createPlayer(shared_ptr<EntityFactory> &factory)
         * @brief Maakt een player aan.
         * @param factory: is een shared_ptr naar een EntityFactory wat de factory die gebruikt wordt om de player aan te maken.
         ****************************************************************************************************/
        void createPlayer(shared_ptr<EntityFactory> &factory);

        /****************************************************************************************************
         * @function void refreshPlayer()
         * @brief Refreshed alle eigenschappen van de speler en zorgt ervoor dat deze geupdate wordt.
         ****************************************************************************************************/
        void refreshPlayer();

        /****************************************************************************************************
         * @function void movePlayerRight()
         * @brief Verplaatst de speler naar rechts.
         ****************************************************************************************************/
        void movePlayerRight();

        /****************************************************************************************************
         * @function void movePlayerLeft()
         * @brief Verplaatst de speler naar links.
         ****************************************************************************************************/
        void movePlayerLeft();

        /****************************************************************************************************
         * @function void playerTouchesPlatform(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer)
         * @brief Controlleerd of de speler collision heeft met een platform.
         * @param leftPlayer is een vector van een pair die 2 floats bevat, wat de linkerboundry coordinaten zijn.
         * @param rightPlayer is een vector van een pair die 2 floats bevat, wat de rechterboundry coordinaten zijn.
         ****************************************************************************************************/
        void playerTouchesPlatform(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer);

        /****************************************************************************************************
         * @function void playerTouchesBoost(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer)
         * @brief Controlleerd of de speler collision heeft met een bonus.
         * @param leftPlayer is een vector van een pair die 2 floats bevat, wat de linkerboundry coordinaten zijn.
         * @param rightPlayer is een vector van een pair die 2 floats bevat, wat de rechterboundry coordinaten zijn.
         ****************************************************************************************************/
        void playerTouchesBoost(vector<pair<float, float>>& leftPlayer, vector<pair<float, float>>& rightPlayer);
        
        /****************************************************************************************************
         * @function void playerOutOfScope()
         * @brief Als de speler out of scope is zal het, het spel eindigen.
         ****************************************************************************************************/
        void playerOutOfScope();

        /*END****************************************** Player ******************************************END*/

        /*BEGIN*************************************** Platform ***************************************BEGIN*/

        /****************************************************************************************************
         * @function void createPlatform(shared_ptr<EntityFactory> &factory, float x, float y)
         * @brief Maakt een platform aan op de plaats van de meegeven coördinaten.
         * @param factory: is een shared_ptr naar een EntityFactory wat de factory die gebruikt wordt om de platform aan te maken.
         * @param x: is een float, de x coördinaat.
         * @param y: is een float, de y coördinaat.
         ****************************************************************************************************/
        void createPlatform(shared_ptr<EntityFactory> &factory, float x, float y);

        /****************************************************************************************************
         * @function void refreshPlatform()
         * @brief Refreshed alle eigenschappen van het platform en zorgt ervoor dat deze geupdate wordt.
         ****************************************************************************************************/
        void refreshPlatform();

        /****************************************************************************************************
         * @function void createAplatform(shared_ptr<EntityFactory> &factory, bool begin = false)
         * @brief Controlleerd of er een platform gemaakt moet worden, als dat zo is dan dan wordt de createPlatform
         * functie aangeroepen.
         * @param factory: is een shared_ptr naar een EntityFactory waar het platform is gemaakt zou worden.
         * @param bool: is een boolean wat betekent zegt of we in het begin van het spel zitten. Wat ervoor
         * zorgt dat er al een x-aantal begin platforms gemaakt worden.
         ****************************************************************************************************/
        void createAplatform(shared_ptr<EntityFactory> &factory, bool begin = false);

        /****************************************************************************************************
         * @function void removePlatform(shared_ptr<Platform_L>& platform)
         * @brief Verwijderd een platform als deze out of scope is.
         * @param platform: is een shared_ptr naar een Platform_L en is het platform dat verwijderd moet worden.
         ****************************************************************************************************/
        void removePlatform(shared_ptr<Platform_L>& platform);

        template<class T>
        void NotifyAll(vector<shared_ptr<T>>& model);

        /*END***************************************** Platform *****************************************END*/

        /*BEGIN**************************************** Score *****************************************BEGIN*/

        /****************************************************************************************************
         * @function void createScore(shared_ptr<EntityFactory> &factory)
         * @brief Maakt een score aan.
         * @param factory: is een shared_ptr naar een EntityFactory wat de factory die gebruikt wordt om de score aan te maken.
         ****************************************************************************************************/
        void createScore(shared_ptr<EntityFactory> &factory);

        /****************************************************************************************************
         * @function int getScore()
         * @brief Geeft de score terug.
         * @return Is een integer wat de net behaalde score is.
         ****************************************************************************************************/
        int getScore();

        /****************************************************************************************************
         * @function int getHighScore()
         * @brief Geeft de al time highscore terug.
         * @return Is een integer wat de al time highscore is.
         ****************************************************************************************************/
        int getHighScore();

        /****************************************************************************************************
         * @function void readSavedScoreFile()
         * @brief Leest een file in en zet de highscore en score.
         ****************************************************************************************************/
        void readSavedScoreFile();

        /*END****************************************** Score *******************************************END*/

        /*BEGIN*************************************** bg_tile ****************************************BEGIN*/

        /****************************************************************************************************
         * @function void createBG_Tile(shared_ptr<EntityFactory> &factory, bool second)
         * @brief Maakt een bg_tile aan.
         * @param factory: is een shared_ptr naar een EntityFactory wat de factory die gebruikt wordt om de bonus aan te maken.
         * @param second: is een bool, omdat we werken met 2 platformen kunnen we dit aanduiden met een boolean.
         * En zo al een bg_tile aan te maken met een offset.
         ****************************************************************************************************/
        void createBG_Tile(shared_ptr<EntityFactory> &factory, bool second);

        /****************************************************************************************************
         * @function void refreshBg_Tile()
         * @brief Refreshed alle eigenschappen van de bg_tile en zorgt ervoor dat deze geupdate wordt.
         ****************************************************************************************************/
        void refreshBg_Tile();

        /****************************************************************************************************
         * @function void tileOutOfView()
         * @brief Kijkt of de tile out of scope is als da zo is dan wordt deze terug boven de andere tile geplaatst.
         ****************************************************************************************************/
        void tileOutOfView();

        /*END***************************************** bg_tile ******************************************END*/

        /*BEGIN**************************************** Bonus *****************************************BEGIN*/

        /****************************************************************************************************
         * @function void createBonus(shared_ptr<EntityFactory> &factory, float x, float y)
         * @brief Maakt een bonus aan op de plaats van de meegeven coördinaten.
         * @param factory: is een shared_ptr naar een EntityFactory wat de factory die gebruikt wordt om de bonus aan te maken.
         * @param x: is een float, de x coördinaat.
         * @param y: is een float, de y coördinaat.
         ****************************************************************************************************/
        void createBonus(shared_ptr<EntityFactory> &factory, float x, float y);

        /****************************************************************************************************
         * @function void refreshBonus()
         * @brief Refreshed alle eigenschappen van de bonus en zorgt ervoor dat deze geupdate wordt.
         ****************************************************************************************************/
        void refreshBonus();

        /****************************************************************************************************
         * @function void removeBonus(shared_ptr<Bonus_L>& bonus)
         * @brief Verwijderd een bonus als deze out of scope is.
         * @param bonus: is een shared_ptr naar een Bonus_L en is de bonus dat verwijderd moet worden.
         ****************************************************************************************************/
        void removeBonus(shared_ptr<Bonus_L>& bonus);

        /*END****************************************** Bonus *******************************************END*/
        void playerCollision();

        ~World();
    };
}

#endif //DOODLE_JUMP_WORLD_H
