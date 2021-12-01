
#include "PlayerFactory.h"

namespace representation {

    PlayerFactory::PlayerFactory() = default;

    void PlayerFactory::createPlayer(shared_ptr<logic::Subject> &subject) {
        subject->addObserver(shared_ptr<logic::Observer> (new representation::Player(subject)));
//        subject->setY(Window::Instance()->getWindow()->getSize().y/2 - subject->m_observers[0]->getHeight()/2);
//        subject->setX(Window::Instance()->getWindow()->getSize().x/2 - subject->m_observers[0]->getWidth()/2);
    }

    void PlayerFactory::createBG_Tile(shared_ptr<logic::Subject> &subject) {}

    void PlayerFactory::createPlatform(shared_ptr<logic::Subject> &subject) {}

    void PlayerFactory::createBonus(shared_ptr<logic::Subject> &subject) {}
}