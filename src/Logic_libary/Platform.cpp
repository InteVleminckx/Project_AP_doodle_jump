#include "Platform.h"

namespace logic {

    Platform_L::Platform_L() = default;

    Platform_L::Platform_L(float posX, float posY, float width, float height) {
        /**
        We werken in het logic gedeelte tussen -1 en 1 in de x-as en -1 en +inf in de y-as
        De begin positie het platform moet dus tussen deze waarde te komen liggen
        Dit geldt dus ook voor de grote van ons platform
        */
        m_x = posX; m_y = posY;
        m_width = width; m_height = height;
    }

    void Platform_L::setTemporary(bool temporary) {m_temporary = temporary;}

    bool Platform_L::isTemporary() const {return m_temporary;}

    Platform_L_static::Platform_L_static() = default;

    Platform_L_static::Platform_L_static(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {}

    Platform_L_vertical::Platform_L_vertical() = default;

    Platform_L_vertical::Platform_L_vertical(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {m_velocityY = .01f;}

    Platform_L_horizontal::Platform_L_horizontal() = default;

    Platform_L_horizontal::Platform_L_horizontal(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {m_velocityX = .01f;}

    Platform_L_temporary::Platform_L_temporary() = default;

    Platform_L_temporary::Platform_L_temporary(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {setTemporary(true);}
}