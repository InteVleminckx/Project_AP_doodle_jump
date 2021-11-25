#include "Player.h"

namespace representation {


    Player::Player() = default;

    Player::Player(shared_ptr<logic::Subject> &subject)
    {
        m_subject = subject;
        createSprite("../Sprites/Doodle_player.png");
    }

    void Player::update() {

        representation::Window::Instance()->getWindow()->draw(m_modelSprite);
    }

}