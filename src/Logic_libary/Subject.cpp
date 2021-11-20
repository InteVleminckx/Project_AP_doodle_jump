#include "Subject.h"
#include "Observer.h"

namespace logic {
    Subject::Subject() {

    }

    void Subject::addObserver(Observer* observer) { m_observers.push_back(observer); }

    void Subject::removeObserver(const Observer* observer)
    {
        for (int i = 0; i < m_observers.size();  ++i)
        {
            if (m_observers[i] == observer)
            {
                cout << "Remove observer out vector: m_obsevers.erase(m_observers->begin() + i)" << endl;
            }
        }
    }

    void Subject::Notify() { for (Observer* ob : m_observers) ob->Update(); }
}
