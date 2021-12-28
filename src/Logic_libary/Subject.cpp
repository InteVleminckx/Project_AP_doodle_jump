#include "Subject.h"
#include "Observer.h"
#include "ControllingPointers.h"

namespace logic {
    Subject::Subject() = default;

    void Subject::addObserver(unique_ptr<Observer> observer){
        ControllingPointers::control(observer, "Subject", "addObserver(unique_ptr<Observer> observer)");
        m_observers.push_back(move(observer));
    }

    void Subject::removeObserver(const unique_ptr<Observer>& observer)
    {
        ControllingPointers::control(observer, "Subject", "removeObserver(const unique_ptr<Observer>& observer)");

        for (int i = 0; i < m_observers.size();  ++i)
        {
            if (m_observers[i] == observer)
            {
               m_observers.erase(m_observers.begin()+i);
            }
        }
    }
    void Subject::emptyObserver() {m_observers.clear();}

    vector<unique_ptr<Observer>>& Subject::getObservers() {return m_observers;}

    Subject::~Subject() {
        cout << "delete Subject"  << endl;
    }


}
