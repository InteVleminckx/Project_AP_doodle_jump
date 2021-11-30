#include "Player.h"

namespace representation {


    Player::Player()= default;

    Player::Player(shared_ptr<logic::Subject> &subject)
    {
        m_width = Window::Instance()->getWindow()->getSize().x/8.5f;
        m_height = Window::Instance()->getWindow()->getSize().y/11.5f;
        m_subject = subject;
        createSprite("../Sprites/Doodle_player.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
        m_subject->setWidth(m_width);
        m_subject->setHeight(m_height);

    }

    void Player::update(float x, float y) {

        m_modelSprite.setPosition(x, y);
        representation::Window::Instance()->getWindow()->draw(m_modelSprite);
    }

}