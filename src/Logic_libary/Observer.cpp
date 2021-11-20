#include "Observer.h"

namespace logic {
    Observer::Observer(Subject& subject) { m_subject = subject; }

    bool Observer::operator==(const Observer &that) {
        return false;
    }

    void Observer::Update() {cout << "Update" << endl; }
}


