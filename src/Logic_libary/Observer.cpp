#include "Observer.h"

namespace logic {

    Observer::Observer() = default;

    Observer::Observer(shared_ptr<logic::Subject>& subject) : m_subject(subject) {}

    bool Observer::operator==(const Observer &that) {
        return false;
    }

    void Observer::update() {cout << "Update" << endl; }


}


