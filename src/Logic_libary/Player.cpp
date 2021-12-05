#include "Player.h"

namespace logic {

    Player_L::Player_L() = default;

    Player_L::Player_L(float posX, float posY, float width, float height) {
        /**
        We werken in het logic gedeelte tussen -1 en 1 in de x-as en -1 en +inf in de y-as
        De begin positie van onze player moet dus tussen deze waarde te komen liggen
        Dit geldt dus ook voor de grote van onze player
        Onze player start midden in het scherm en wordt vanaf 0 gelauched naar boven op de y-as
        Dus het centrum van onze player in het begin zou eigl (0,-1) moeten zijn
        */

        m_x  = posX; m_y = posY;
        m_xPrev  = posX; m_yPrev = posY;
        m_velocityX = 1.5f;
        m_gravity = 1.5f;
        m_width = width; m_height = height;

    }

    void Player_L::gravity() {
        setVelocityY(getVelocityY() - m_gravity * Stopwatch::Instance()->GetDeltaTime());
        EntityModel::setYprev(m_y);
        setY(getY() + (getVelocityY() * Stopwatch::Instance()->GetDeltaTime()));
    }

    void Player_L::moveRight() {

        float newPos = getX() + (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());

        if (newPos >= 1.f)
            newPos = 0;
        EntityModel::setXprev(m_x);
        setX(newPos);

    }

    void Player_L::moveLeft() {
        float newPos = getX() - (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());
        if (newPos <= 0)
            newPos = 1.f;
        EntityModel::setXprev(m_x);
        setX(newPos);
    }

    void Player_L::jump() {m_velocityY = sqrt(2.0f * m_gravity * m_jumpforce);}


}


