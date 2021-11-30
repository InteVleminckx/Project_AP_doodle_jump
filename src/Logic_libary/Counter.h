/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_COUNTER_H
#define DOODLE_JUMP_COUNTER_H

#include <iostream>
#include <chrono>

using namespace std;

namespace logic {
    class Counter {

        static Counter* s_instance;
        chrono::system_clock::time_point m_startTime;
        chrono::duration<float> m_deltaTime{};

    public:

        static Counter* Instance();

        static void Release();

        void Reset();

        float GetDeltaTime();

        void Tick();

    private:

        Counter();

        ~Counter();

    };

}





#endif //DOODLE_JUMP_COUNTER_H
