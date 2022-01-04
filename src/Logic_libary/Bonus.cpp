#include "Bonus.h"

namespace logic {


    Bonus_L::Bonus_L(float posX, float posY, float width, float height) {
        setX(posX); setY(posY);
        setWidth(width); setHeight(height);
    }

    float Bonus_L::getForce() {
        return m_bonusforce;
    }

    bool Bonus_L::getInvolmsVelocity() {
        return m_involmsVeloctiy;
    }

    void Bonus_L::setIncreasingValue(int value) {
        m_increasingValue = value;
    }

    int Bonus_L::getIncreasingValue() {
        return m_increasingValue;
    }

    Spring_L::Spring_L(float posX, float posY, float width, float height) : Bonus_L(posX, posY, width, height) {
        // 5x zo groot als normaal
        m_bonusforce = 5*0.75f;
        m_involmsVeloctiy = true;
        setIncreasingValue(750);
    }

    Rocket_L::Rocket_L(float posX, float posY, float width, float height) : Bonus_L(posX, posY, width, height) {
        //zelf te kiezen
        m_bonusforce = 5.f;
        m_involmsVeloctiy = false;
        setIncreasingValue(1500);
    }

    Bonus_L::~Bonus_L() = default;

    Spring_L::~Spring_L() = default;

    Rocket_L::~Rocket_L() = default;
}
