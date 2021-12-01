#include "Player.h"

namespace logic {

    Player_L::Player_L() {
        /**
        We werken in het logic gedeelte tussen -1 en 1 in de x-as en -1 en +inf in de y-as
        De begin positie van onze player moet dus tussen deze waarde te komen liggen
        Dit geldt dus ook voor de grote van onze player
        Onze player start midden in het scherm en wordt vanaf 0 gelauched naar boven op de y-as
        Dus het centrum van onze player in het begin zou eigl (0,-1) moeten zijn
        */

        m_x  = 0.0f; m_y = 1.0f;
        m_velocityY = .015f;
        m_velocityX = 2.0f;
    }

    void Player_L::gravity() {


//        if (m_velocityY > -9.81f)
//        {
//            m_velocityY = (-logic::Counter::Instance()->GetDeltaTime() * 9.81f * 60.0f) /
//                            (1/logic::Stopwatch::Instance()->GetDeltaTime());
//        }
//
//        else if (m_velocityY < -9.81f)
//        {
//            m_velocityY = -9.81f;
//            logic::Counter::Instance()->Release();
//        }
        setY(getY() - getVelocityY());
    }

    void Player_L::moveRight() {

        float newPos = getX() + (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());

        if (newPos >= 1.f)
            newPos = -1.f;
        setX(newPos);

    }

    void Player_L::moveLeft() {
        float newPos = getX() - (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());
        if (newPos <= -1.f)
            newPos = 1.f;
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


