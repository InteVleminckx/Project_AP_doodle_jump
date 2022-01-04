//
// Created by inte on 11/18/21.
//

#include "Stopwatch.h"

namespace logic {

    Stopwatch* Stopwatch::s_instance = nullptr;

    Stopwatch* Stopwatch::Instance() {
        if (s_instance == nullptr)
            s_instance = new Stopwatch;
        return s_instance;
    }

    void Stopwatch::Release() {
        delete s_instance;
        s_instance = nullptr;
    }

    Stopwatch::Stopwatch() {
        Reset();
        m_deltaTime = chrono::duration<float>(0.0f);
    }

    void Stopwatch::Reset() {
        m_startTime = chrono::system_clock::now();
    }

    float Stopwatch::GetDeltaTime() {
        return m_deltaTime.count();
    }

    void Stopwatch::Tick() {
        m_deltaTime = chrono::system_clock::now() - m_startTime;
    }

    Stopwatch::~Stopwatch() = default;


}