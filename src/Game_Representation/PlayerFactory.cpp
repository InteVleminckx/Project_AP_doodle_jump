
#include "PlayerFactory.h"

namespace representation {

    PlayerFactory::PlayerFactory() = default;

    void PlayerFactory::createPlayer(shared_ptr<logic::Subject> &subject) {
        subject->addObserver(shared_ptr<logic::Observer> (new representation::Player(subject)));
    }

    void PlayerFactory::createBG_Tile(shared_ptr<logic::Subject> &subject) {}

    void PlayerFactory::createPlatform(shared_ptr<logic::Subject> &subject) {}

    void PlayerFactory::createBonus(shared_ptr<logic::Subject> &subject) {}
}