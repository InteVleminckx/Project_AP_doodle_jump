/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class ConcreteFactory
 * @BaseClass EntityFactory
 * @SubClasses None
 * @Namespace representation
 * @brief Staat in om alle EntityViews (observers) aan te maken.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_CONCRETEFACTORY_H
#define DOODLE_JUMP_CONCRETEFACTORY_H

#include <iostream>
#include "../Logic_libary/EntityFactory.h"
#include "../Game_Representation/Player.h"
#include "../Game_Representation/Platform.h"
#include "../Game_Representation/BG_Tile.h"
#include "../Game_Representation/Bonus.h"
#include "../Game_Representation/Score.h"

using namespace std;

namespace representation {
    class ConcreteFactory : public logic::EntityFactory{

    public:

        /****************************************************************************************************
         * @function ConcreteFactory()
         * @brief Default constructor.
         ****************************************************************************************************/
        ConcreteFactory();

        /****************************************************************************************************
         * @function void createPlayer(shared_ptr<logic::Player_L> &subject) override
         * @brief Maakt een nieuwe Player aan dat een observer is en wordt toegevoegd aan het subject player.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param player: een shared_ptr naar een Player_L wat een afleiding is van een EnityModel.
         ****************************************************************************************************/
        void createPlayer(const shared_ptr<logic::Player_L> &player) override;

        /****************************************************************************************************
         * @function void createBG_Tile(shared_ptr<logic::BG_Tile_L> &bg_tile) override
         * @brief Maakt een nieuwe BG_Tile aan dat een observer is en wordt toegevoegd aan het subject bg_tile.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param bg_tile: een shared_ptr naar een BG_Tile_L wat een afleiding is van een EnityModel.
         ****************************************************************************************************/
        void createBG_Tile(const shared_ptr<logic::BG_Tile_L> &bg_tile) override;

        /****************************************************************************************************
         * @function void createPlatform(shared_ptr<logic::Platform_L> &platform, _Platform type) override
         * @brief Maakt een nieuw Platform aan naargelang het type, dat een observer is en wordt toegevoegd aan het subject platform.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param platform: een shared_ptr naar een Platform_L wat een afleiding is van een EnityModel.
         * @param type: bevat het de soort van het platform dat aangemaakt moet worden. (Static, Horizontal, Vertical, Temporary)
         ****************************************************************************************************/
        void createPlatform(const shared_ptr<logic::Platform_L> &platform, PlatformType type) override;

        /****************************************************************************************************
         * @function void createBonus(shared_ptr<logic::Bonus_L> &bonus, _Bonus type) override
         * @brief Maakt een nieuwe Bonus aan naargelang het type, dat een observer is en wordt toegevoegd aan de subject bonus.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param bonus: een shared_ptr naar een Bonus_L wat een afleiding is van een EnityModel.
         * @param type: bevat het de soort van de bonus dat aangemaakt moet worden. (Spring, Rocket)
         ****************************************************************************************************/
        void createBonus(const shared_ptr<logic::Bonus_L> &bonus, BonusType type) override;

        /****************************************************************************************************
         * @function void createScore(shared_ptr<logic::Player_L> &player, shared_ptr<logic::Score>& score) override
         * @brief Maakt een nieuwe score aan dat een observer is en wordt toegevoegd aan de subject player.
         * Deze functie wordt overschreven uit de base class EntityFactory.
         * @param player: een shared_ptr naar een Player_L wat een afleiding is van een EnityModel.
         ****************************************************************************************************/
        void createScore(const shared_ptr<logic::Player_L> &player) override;

        ~ConcreteFactory() override;

    };
}


#endif //DOODLE_JUMP_CONCRETEFACTORY_H
