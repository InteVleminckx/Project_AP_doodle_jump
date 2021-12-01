//
// Created by inte on 11/25/21.
//

#include "PlatformFactory.h"

namespace representation {

    PlatformFactory::PlatformFactory() = default;

    void PlatformFactory::createPlatform(shared_ptr<logic::Subject> &subject) {
        subject->addObserver(shared_ptr<logic::Observer> (new representation::Platform_static(subject)));
    }
}