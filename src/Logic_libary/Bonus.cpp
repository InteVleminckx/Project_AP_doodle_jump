#include "Bonus.h"

namespace logic {

    Bonus::Bonus() = default;

    Spring::Spring() = default;

    Rocket::Rocket() = default;

    Bonus::Bonus(float posX, float posY, float width, float height) {
        m_x  = posX; m_y = posY;
        m_width = width; m_height = height;
    }

    Spring::Spring(float posX, float posY, float width, float height) : Bonus(posX, posY, width, height) {
        // 5x zo groot als normaal
        m_bonusforce = 2.5f;
    }

    Rocket::Rocket(float posX, float posY, float width, float height) : Bonus(posX, posY, width, height) {
        //zelf te kiezen
        m_bonusforce = 5.f;
    }
}
