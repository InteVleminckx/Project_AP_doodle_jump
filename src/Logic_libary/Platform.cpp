#include "Platform.h"

namespace logic {

    Platform_L::Platform_L(float posX, float posY, float width, float height) {
        /**
        We werken in het logic gedeelte tussen -1 en 1 in de x-as en -1 en +inf in de y-as
        De begin positie het platform moet dus tussen deze waarde te komen liggen
        Dit geldt dus ook voor de grote van ons platform
        */
        setX(posX); setY(posY);
        setXprev(posX); setYprev(posY);
        setWidth(width); setHeight(height);
    }

    void Platform_L::setTemporary(bool temporary) {m_temporary = temporary;}

    bool Platform_L::isTemporary() {return m_temporary;}

    void Platform_L::setStartPostionY(float y) {m_startPositionY = y;}

    float Platform_L::getStartPositionY() {return m_startPositionY;}

    Platform_L_static::Platform_L_static(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {}

    void Platform_L_static::movePlatform() {}

    void Platform_L_static::changeDirection() {}

    Platform_L_vertical::Platform_L_vertical(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {
        setVelocityY(.2f);
        setStartPostionY(posY);
    }

    void Platform_L_vertical::movePlatform() {

        float newPos = getY() - (getVelocityY() * Stopwatch::Instance()->GetDeltaTime());
        setYprev(getY());
        setY(newPos);

        if (abs(getY() - getStartPositionY()) >= 0.25f) changeDirection();

    }

    void Platform_L_vertical::changeDirection() {
        setVelocityY(-getVelocityY());
    }

    Platform_L_horizontal::Platform_L_horizontal(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {
        setVelocityX(.2f);
    }

    void Platform_L_horizontal::movePlatform() {
        float newPos = getX() - (getVelocityX() * Stopwatch::Instance()->GetDeltaTime());
        setXprev(getX());
        setX(newPos);

        if (getX() <= 0) changeDirection();
        else if (getX() + getWidth() >= 1) changeDirection();
    }

    void Platform_L_horizontal::changeDirection() {
        setVelocityX(-getVelocityX());
    }

    Platform_L_temporary::Platform_L_temporary(float posX, float posY, float width, float height) : Platform_L(posX, posY, width, height) {setTemporary(true);}

    void Platform_L_temporary::movePlatform() {}

    void Platform_L_temporary::changeDirection() {}
}