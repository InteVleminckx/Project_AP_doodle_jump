//
// Created by inte on 11/18/21.
//

#include "Counter.h"

namespace logic {

    Counter* Counter::s_instance = nullptr;

    Counter* Counter::Instance() {
        if (s_instance == nullptr)
            s_instance = new Counter;
        return s_instance;
    }

    void Counter::Release() {
        delete s_instance;
        s_instance = nullptr;
    }

    Counter::Counter() {
        Reset();
        m_deltaTime = chrono::duration<float>(0.0f);
    }

    Counter::~Counter() {}

    void Counter::Reset() {
        m_startTime = chrono::system_clock::now();
    }

    float Counter::GetDeltaTime() {
        return m_deltaTime.count() - 1;
    }

    void Counter::Tick() {
        m_deltaTime = chrono::system_clock::now() - m_startTime;
    }


}