#include "Bonus.h"

namespace logic {

    Bonus_L::Bonus_L() = default;

    Spring_L::Spring_L() = default;

    Rocket_L::Rocket_L() = default;

    Bonus_L::Bonus_L(float posX, float posY, float width, float height) {
        setX(posX); setY(posY);
        setWidth(width); setHeight(height);
    }

    float Bonus_L::getForce() {
        return m_bonusforce;
    }

    Spring_L::Spring_L(float posX, float posY, float width, float height) : Bonus_L(posX, posY, width, height) {
        // 5x zo groot als normaal
        m_bonusforce = 2.5f;
    }

    Rocket_L::Rocket_L(float posX, float posY, float width, float height) : Bonus_L(posX, posY, width, height) {
        //zelf te kiezen
        m_bonusforce = 5.f;
    }
}
