#include "Player.h"

namespace logic {
    void Player_L::gravity() {


        if (m_velocityY > -9.81f)
        {
            m_velocityY = (-logic::Counter::Instance()->GetDeltaTime() * 9.81f * 60.0f) /
                            (1/logic::Stopwatch::Instance()->GetDeltaTime());
        }

        else if (m_velocityY < -9.81f)
        {
            m_velocityY = -9.81f;
            logic::Counter::Instance()->Release();
        }
        setY(getY() - getVelocityY());
    }

    void Player_L::moveRight() {

        float newPos = getX() + (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());

        if (newPos >= representation::Window::Instance()->getWindow()->getSize().x)
            newPos = -m_observers[0]->getWidth();
        setX(newPos);

    }

    void Player_L::moveLeft() {
        float newPos = getX() - (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());
        if (newPos + m_observers[0]->getWidth() <= 0)
            newPos = representation::Window::Instance()->getWindow()->getSize().x;
        setX(newPos);
    }

    void Player_L::jump() {
        //zet "gravity" naar het omgekeerde
        m_velocityY = -m_velocityY;

        //start een telleler die van 1 naar -1 telt op 2 seconden
        //1, 0.99, 0.98 -> -0.98, -0.99, -1
        //geeft dan een sprong effect dit getal doen we dan telkens maal de m_velocityY
        logic::Counter::Instance()->Reset();


    }


}


