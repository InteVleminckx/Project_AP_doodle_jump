/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class EntityFactory
 * @BaseClass none
 * @SubClasses ConcreteFactory
 * @Namespace logic
 * @brief Staat in om alle EntityViews (observers) aan te maken.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_ENTITYFACTORY_H
#define DOODLE_JUMP_ENTITYFACTORY_H

#include <iostream>
#include "../Logic_libary/Platform.h"
#include "../Logic_libary/Player.h"
#include "../Logic_libary/BG_Tile.h"
#include "../Logic_libary/Bonus.h"
#include "../Logic_libary/Score_L.h"

using namespace std;

/****************************************************************************************************
 * @enum PlatformType
 * @brief Bevat alle soorten platforms.
****************************************************************************************************/
enum PlatformType {Static_, Horizontal_, Vertical_, Temporary_};

/****************************************************************************************************
 * @enum BonusType
 * @brief Bevat alle soorten bonussen.
****************************************************************************************************/
enum BonusType {Rocket_, Spring_};

namespace logic {

    class EntityFactory {
    public:

        /****************************************************************************************************
         * @function EntityFactory()
         * @brief Default constructor.
         ****************************************************************************************************/
        EntityFactory();

        /****************************************************************************************************
         * @function void createPlayer(shared_ptr<logic::Player_L> &subject)
         * @brief Maakt een nieuwe Player aan dat een observer is en wordt toegevoegd aan het subject player.
         * Deze functie is pure virtual void function.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param player: een shared_ptr naar een Player_L wat een afleiding is van een EnityModel.
         ****************************************************************************************************/
        virtual void createPlayer(const shared_ptr<Player_L>& subject) = 0;

        /****************************************************************************************************
         * @function void createBG_Tile(shared_ptr<logic::BG_Tile_L> &bg_tile)
         * @brief Maakt een nieuwe BG_Tile aan dat een observer is en wordt toegevoegd aan het subject bg_tile.
         * Deze functie is pure virtual void function.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param bg_tile: een shared_ptr naar een BG_Tile_L wat een afleiding is van een EnityModel.
         ****************************************************************************************************/
        virtual void createPlatform(const shared_ptr<Platform_L>& subject, PlatformType type) = 0;

        /****************************************************************************************************
         * @function void createPlatform(shared_ptr<logic::Platform_L> &platform, _Platform type) override
         * @brief Maakt een nieuw Platform aan naargelang het type, dat een observer is en wordt toegevoegd aan het subject platform.
         * Deze functie is pure virtual void function.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param platform: een shared_ptr naar een Platform_L wat een afleiding is van een EnityModel.
         * @param type: bevat het de soort van het platform dat aangemaakt moet worden. (Static, Horizontal, Vertical, Temporary)
         ****************************************************************************************************/
        virtual void createBG_Tile(const shared_ptr<BG_Tile_L>& subject) = 0;

        /****************************************************************************************************
         * @function void createBonus(shared_ptr<logic::Bonus_L> &bonus, _Bonus type)
         * @brief Maakt een nieuwe Bonus aan naargelang het type, dat een observer is en wordt toegevoegd aan de subject bonus.
         * Deze functie is pure virtual void function.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param bonus: een shared_ptr naar een Bonus_L wat een afleiding is van een EnityModel.
         * @param type: bevat het de soort van de bonus dat aangemaakt moet worden. (Spring, Rocket)
         ****************************************************************************************************/
        virtual void createBonus(const shared_ptr<Bonus_L>& subject, BonusType type) = 0;

        /****************************************************************************************************
         * @function void createScore(shared_ptr<logic::Player_L> &player, shared_ptr<logic::Score>& score)
         * @brief Maakt een nieuwe score aan dat een observer is en wordt toegevoegd aan de subject player.
         * Deze functie is pure virtual void function.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param player: een shared_ptr naar een Player_L wat een afleiding is van een EnityModel.
         ****************************************************************************************************/
        virtual void createScore(const shared_ptr<Player_L>& subject) = 0;

        virtual ~EntityFactory();

    };
}


#endif //DOODLE_JUMP_ENTITYFACTORY_H
