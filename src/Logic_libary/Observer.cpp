#include "Observer.h"

namespace logic {

    Observer::Observer() = default;

    Observer::Observer(shared_ptr<logic::Subject>& subject) : m_subject(subject) {}

    bool Observer::operator==(const Observer &that) {
        if (this->m_subject == that.m_subject) return true;
        return false;
    }


}


