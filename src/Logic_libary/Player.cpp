#include "Player.h"

namespace logic {

    Player_L::Player_L(float posX, float posY, float width, float height) {
        /**
        We werken in het logic gedeelte tussen -1 en 1 in de x-as en -1 en +inf in de y-as
        De begin positie van onze player moet dus tussen deze waarde te komen liggen
        Dit geldt dus ook voor de grote van onze player
        Onze player start midden in het scherm en wordt vanaf 0 gelauched naar boven op de y-as
        Dus het centrum van onze player in het begin zou eigl (0,-1) moeten zijn
        */
        setX(posX); setY(posY);
        setXprev(posX); setYprev(posY);
        setVelocityX(1.f);
        setGravity(3.f);
        setWidth(width); setHeight(height);
    }

    void Player_L::gravity() {

        if (getVelocityY() < 0 && m_bonusActive) m_bonusActive = false;

        setVelocityY(getVelocityY() - getGravity() * Stopwatch::Instance()->GetDeltaTime());
        setYprev(getY());
        setY(getY() + (getVelocityY() * Stopwatch::Instance()->GetDeltaTime()));
        logic::Camera::Instance()->setOffset(getY());
    }

    void Player_L::moveRight(float leftBound, float rightBound) {

        float newPos = getX() + (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());

        if (newPos >= rightBound)
            newPos = leftBound;
        setXprev(getX());
        setX(newPos);

    }

    void Player_L::moveLeft(float leftBound, float rightBound) {
        float newPos = getX() - (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());
        if (newPos <= leftBound)
            newPos = rightBound;
        setXprev(getX());
        setX(newPos);
    }

    void Player_L::jump() { setVelocityY(sqrt(2.0f * getGravity() * m_jumpforce));}

    void Player_L::powerup(float power) {
        if (!m_bonusActive)
        {
            m_bonusActive = true;
            setVelocityY(sqrt(2.0f * getGravity() * power));
        }
    }

    Player_L::~Player_L() {
        cout << "delete Player_L"  << endl;

    }


}


