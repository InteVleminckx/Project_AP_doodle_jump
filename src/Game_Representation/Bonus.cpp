#include "Bonus.h"

namespace representation {

    Bonus::Bonus() = default;

    Spring::Spring() = default;

    Rocket::Rocket() = default;

    Bonus::Bonus(shared_ptr<logic::Subject> &subject) {
        m_width =  logic::Camera::Instance()->getCameraWidth() * subject->getWidth();
        m_height = logic::Camera::Instance()->getCameraHeight() * subject->getHeight();
        m_subject = subject;
    }

    Spring::Spring(shared_ptr<logic::Subject> &subject) : Bonus(subject) {
        createSprite("../Spring.png");
        m_modelSprite.setScale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }

    Rocket::Rocket(shared_ptr<logic::Subject> &subject) : Bonus(subject){
        createSprite("../Rocket.png");
        m_modelSprite.setScale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }
}