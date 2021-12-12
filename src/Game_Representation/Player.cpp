#include "Player.h"

namespace representation {

    Player::Player()= default;

    Player::Player(shared_ptr<logic::Subject> &subject) {
        m_width =  logic::Camera::Instance()->getCameraWidth() * subject->getWidth();
        m_height = logic::Camera::Instance()->getCameraHeight() * subject->getHeight();
        m_subject = subject;

        createSprite("../Sprites/Doodle_player2.png");
        m_modelSprite.setScale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }
}