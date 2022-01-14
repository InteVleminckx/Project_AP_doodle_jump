//
// Created by inte on 11/18/21.
//

#include "Stopwatch.h"

namespace logic {

Stopwatch& Stopwatch::Instance()
{
        static Stopwatch instance;
        return instance;
}

Stopwatch::Stopwatch()
{
        Reset();
        m_deltaTime = chrono::duration<float>(0.0f);
}

void Stopwatch::Reset() { m_startTime = chrono::system_clock::now(); }

float Stopwatch::GetDeltaTime() { return m_deltaTime.count(); }

void Stopwatch::Tick() { m_deltaTime = chrono::system_clock::now() - m_startTime; }

Stopwatch::~Stopwatch() = default;

} // namespace logic