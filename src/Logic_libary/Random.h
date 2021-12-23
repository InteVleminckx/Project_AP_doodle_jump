/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Random
 * @BaseClass none
 * @SubClasses none
 * @Namespace logic
 * @brief Is een singleton implementatie.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_RANDOM_H
#define DOODLE_JUMP_RANDOM_H

#include <iostream>
#include <time.h>
#include <random>
#include "EntityFactory.h"

using namespace std;

namespace logic {
    class Random {

        /****************************************************************************************************
         * @brief Een pointer naar het random object.
         * @type static Random*
         * @var m_instance
         ****************************************************************************************************/
        static Random* s_instance;

        /****************************************************************************************************
         * @function Random()
         * @brief Wanneer er een random object wordt aangemaakt wordt eerst de seed opnieuw ingesteld.
         ****************************************************************************************************/
        Random();

    public:

        /****************************************************************************************************
         * @function static Random* Instance()
         * @return static Random* het random object.
         ****************************************************************************************************/
        static Random* Instance();

        /****************************************************************************************************
         * @function static void Release()
         * @brief Verwijderd de pointer naar het random object.
         ****************************************************************************************************/
        static void Release();

        /****************************************************************************************************
         * @function PlatformType getPlatformType()
         * @brief Genereert een random platform op basis van de score.
         * @return Een platform type.
         ****************************************************************************************************/
        PlatformType getPlatformType();

        /****************************************************************************************************
         * @function BonusType getBonusType()
         * @brief Genereert een random bonus op basis van de score.
         * @return Een bonus type.
         ****************************************************************************************************/
        BonusType getBonusType();

        /****************************************************************************************************
         * @function bool createPlatform()
         * @brief Zegt of er een platform gegenereerd moet worden op basis van de score.
         * @return Een boolean die zegt of het gegenereerd moet worden of niet?
         ****************************************************************************************************/
        bool createPlatform();

        /****************************************************************************************************
         * @function bool createBonus()
         * @brief Zegt of er een bonus gegenereerd moet worden op basis van de score.
         * @return Een boolean die zegt of het gegenereerd moet worden of niet?
         ****************************************************************************************************/
        bool createBonus();

        /****************************************************************************************************
         * @function float giveRandomX(float leftBound, float rightBound)
         * @brief Geeft een random x terug tussen 2 waarde bepaald door de argumenten.
         * @param leftBound: is een float wat de kleinste waarde is die gegenereerd kan worden.
         * @param rightBound: is een float wat de grootste waarde is die gegenereerd kan worden.
         * @return Een float, wat de random waarde is.
         ****************************************************************************************************/
        float giveRandomX(float leftBound, float rightBound);

        /****************************************************************************************************
         * @function void Reset()
         * @brief Reset de time als seed voor de random functie.
         ****************************************************************************************************/
        void Reset();

    private:

        /****************************************************************************************************
         * @function ~Random()
         * @brief Is een defeault destructor.
         ****************************************************************************************************/
        ~Random();

    };
}


#endif //DOODLE_JUMP_RANDOM_H
