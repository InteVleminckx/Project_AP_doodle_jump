//
// Created by inte on 11/25/21.
//

#include "PlatformFactory.h"

namespace representation {

    PlatformFactory::PlatformFactory() = default;

    void PlatformFactory::createPlatform(shared_ptr<logic::Subject> &subject) {
        subject->addObserver(shared_ptr<logic::Observer> (new representation::Platform_static(subject)));
        subject->setY(Window::Instance()->getWindow()->getSize().y/2 - subject->m_observers[0]->getHeight()/2 + 150);
        subject->setX(Window::Instance()->getWindow()->getSize().x/2 - subject->m_observers[0]->getWidth()/2);
    }
}