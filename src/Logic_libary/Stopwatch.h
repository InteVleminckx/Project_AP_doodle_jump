/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_STOPWATCH_H
#define DOODLE_JUMP_STOPWATCH_H

#include <iostream>
#include <chrono>

using namespace std;

namespace logic {
    class Stopwatch {

        static Stopwatch* s_instance;
        chrono::system_clock::time_point m_startTime;
        chrono::duration<float> m_deltaTime;
        float m_timeScale;

    public:

        static Stopwatch* Instance();

        static void Release();

        void Reset();

        float GetDeltaTime();

        void SetTimeScale(float t = 1.0f);

        float  GetTimeScale();

        void Tick();

    private:

        Stopwatch();

        ~Stopwatch();

    };

}





#endif //DOODLE_JUMP_STOPWATCH_H
