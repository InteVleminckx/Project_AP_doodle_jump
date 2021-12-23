/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Stopwatch
 * @BaseClass none
 * @SubClasses none
 * @Namespace logic
 * @brief Is een singleton implementatie.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_STOPWATCH_H
#define DOODLE_JUMP_STOPWATCH_H

#include <iostream>
#include <chrono>

using namespace std;

namespace logic {
    class Stopwatch {

        /****************************************************************************************************
         * @brief Een pointer naar de Stopwatch.
         * @type static Stopwatch*
         * @var m_instance
         ****************************************************************************************************/
        static Stopwatch* s_instance;

        /****************************************************************************************************
         * @brief Is de starttijd vanaf de chrono wordt geactiveerd.
         * @type chrono::system_clock::time_point
         * @var m_startTime
         ****************************************************************************************************/
        chrono::system_clock::time_point m_startTime;

        /****************************************************************************************************
         * @brief Is tijd die is afgenomen wanneer de chrono is gestart tot deze is gestopt.
         * @type chrono::duration<float>
         * @var m_deltaTime
         ****************************************************************************************************/
        chrono::duration<float> m_deltaTime{};

        /****************************************************************************************************
         * @function Stopwatch()
         * @brief Wanneer er een stopwatch wordt aangemaakt zal de deltaTime op 0 gezet worden en wordt de
         * reset function ook nog is aangeroepen.
         ****************************************************************************************************/
        Stopwatch();

    public:

        /****************************************************************************************************
         * @function static Stopwatch* Instance()
         * @return static Stopwatch* de stopwatch
         ****************************************************************************************************/
        static Stopwatch* Instance();

        /****************************************************************************************************
         * @function static void Release()
         * @brief Verwijderd de pointer naar de stopwatch.
         ****************************************************************************************************/
        static void Release();

        /****************************************************************************************************
         * @function void Reset()
         * @brief Het reset de start time.
         ****************************************************************************************************/
        void Reset();

        /****************************************************************************************************
         * @function float GetDeltaTime()
         * @brief Het geeft de deltaTime terug
         * @return float wat de deltaTime is.
         ****************************************************************************************************/
        float GetDeltaTime();

        /****************************************************************************************************
         * @function void Tick()
         * @brief Het ticked de stopwatch, hoe meet dus hoelang de chrono de tijd heeft opgenomen.
         ****************************************************************************************************/
        void Tick();

    private:

        /****************************************************************************************************
         * @function ~Stopwatch()
         * @brief Is een defeault destructor.
         ****************************************************************************************************/
        ~Stopwatch();

    };

}





#endif //DOODLE_JUMP_STOPWATCH_H
