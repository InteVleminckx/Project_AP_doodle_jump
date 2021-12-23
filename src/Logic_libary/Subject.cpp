#include "Subject.h"
#include "Observer.h"

namespace logic {
    Subject::Subject() = default;

    void Subject::addObserver(const shared_ptr<Observer>& observer)
    { m_observers.push_back(observer); }

    void Subject::removeObserver(const shared_ptr<Observer>& observer)
    {
        for (int i = 0; i < m_observers.size();  ++i)
        {
            if (m_observers[i] == observer)
            {
               m_observers.erase(m_observers.begin()+i);
            }
        }
    }
    void Subject::emptyObserver() {m_observers.clear();}

    vector<shared_ptr<Observer>> Subject::getObservers() {return m_observers;}


}
