//
// Created by inte on 11/17/21.
//

#include "Observer.h"

Observer::Observer(Subject& subject) { m_subject = subject; }

bool Observer::operator==(const Observer &that) {
    return false;
}

void Observer::Update() {cout << "Update" << endl; }
