#include "Player.h"

namespace representation {


    Player::Player()= default;

    Player::Player(shared_ptr<logic::Subject> &subject)
    {
        float scale = Window::Instance()->getWindow()->getSize().x;
        m_width =  scale * subject->getWidth();
        m_height = scale * subject->getHeight();
        m_subject = subject;
        createSprite("../Sprites/Doodle_player.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }

    void Player::update() {

        float x = Window::Instance()->getWindow()->getSize().x*m_subject->getX()-m_width/2;
        float y = Window::Instance()->getWindow()->getSize().y - (m_subject->getY()*Window::Instance()->getWindow()->getSize().y)-m_height/2;
        m_modelSprite.setPosition(x, y);
//        cout << m_modelSprite.getPosition().x << " " << m_modelSprite.getPosition().y << endl;
        representation::Window::Instance()->getWindow()->draw(m_modelSprite);
    }

}