//
// Created by inte on 11/18/21.
//

#include "Player.h"

namespace representation {


    Player::Player() = default;

    Player::Player(shared_ptr<logic::Subject> &subject)
    {
        m_subject = subject;
        createSprite("../Sprites/Doodle_player.png");

    }

    void Player::update() {
        representation::Window* window = representation::Window::Instance();
        m_modelSprite.setPosition(dynamic_pointer_cast<logic::Player_L>(m_subject)->getX(), dynamic_pointer_cast<logic::Player_L>(m_subject)->getY());
        window->getWindow()->draw(m_modelSprite);
    }



}