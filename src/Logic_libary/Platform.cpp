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
        m_xPrev  = posX; m_yPrev = posY;
        m_width = width; m_height = height;
    }

    void Platform_L::setTemporary(bool temporary) {m_temporary = temporary;}

    bool Platform_L::isTemporary() const {return m_temporary;}

    void Platform_L::setStartPostionY(float y) {m_startPositionY = y;}

    float Platform_L::getStartPositionY() {return m_startPositionY;}

    Platform_L_static::Platform_L_static() = default;

    Platform_L_static::Platform_L_static(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {}

    Platform_L_vertical::Platform_L_vertical() = default;

    Platform_L_vertical::Platform_L_vertical(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {
        setVelocityY(.2f);
        setStartPostionY(posY);
    }

    void Platform_L_vertical::movePlatform() {

        setY(getY() - (getVelocityY() * Stopwatch::Instance()->GetDeltaTime()));

        if (abs(getY() - getStartPositionY()) >= 0.25f) changeDirection();

    }

    void Platform_L_vertical::changeDirection() {
        setVelocityY(-getVelocityY());
    }

    Platform_L_horizontal::Platform_L_horizontal() = default;

    Platform_L_horizontal::Platform_L_horizontal(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {
        setVelocityX(.2f);
    }

    void Platform_L_horizontal::movePlatform() {
        setX(getX() - (getVelocityX() * Stopwatch::Instance()->GetDeltaTime()));
        if (getX() <= 0) changeDirection();
        else if (getX() + getWidth() >= 1) changeDirection();
    }

    void Platform_L_horizontal::changeDirection() {
        setVelocityX(-getVelocityX());
    }

    Platform_L_temporary::Platform_L_temporary() = default;

    Platform_L_temporary::Platform_L_temporary(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {setTemporary(true);}
}