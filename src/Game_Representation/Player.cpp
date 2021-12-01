#include "Player.h"

namespace representation {


    Player::Player()= default;

    Player::Player(shared_ptr<logic::Subject> &subject)
    {
        m_width = Window::Instance()->getWindow()->getSize().x*subject->getWidth();
        m_height = Window::Instance()->getWindow()->getSize().y*subject->getHeight();
        m_subject = subject;
        createSprite("../Sprites/Doodle_player.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);

    }

    void Player::update() {

        float x = Window::Instance()->getWindow()->getSize().x/2 + (Window::Instance()->getWindow()->getSize().x/2 * m_subject->getX()) - m_width/2;
        float y = Window::Instance()->getWindow()->getSize().y/2 + (Window::Instance()->getWindow()->getSize().y/2 * (-m_subject->getY())) - m_height /2;
        m_modelSprite.setPosition(x, y);
        representation::Window::Instance()->getWindow()->draw(m_modelSprite);
    }

}