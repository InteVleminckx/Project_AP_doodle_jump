#include "Platform.h"

namespace representation {

    Platform::Platform() = default;

    Platform::Platform(shared_ptr<logic::Subject>& subject) {
        m_width =  logic::Camera::Instance()->getCameraWidth() * subject->getWidth();
        m_height = logic::Camera::Instance()->getCameraHeight() * subject->getHeight();
        m_subject = subject;
    }

    Platform_static::Platform_static(shared_ptr<logic::Subject>& subject) : Platform(subject){
        createSprite("../Sprites/Static_platforms.png");
        m_modelSprite.setScale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }

    Platform_vertical::Platform_vertical(shared_ptr<logic::Subject>& subject) : Platform(subject) {

        createSprite("../Sprites/Vertical_platforms.png");
        m_modelSprite.setScale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }

    Platform_horizontal::Platform_horizontal(shared_ptr<logic::Subject>& subject) : Platform(subject) {
        createSprite("../Sprites/Horizontal_platforms.png");
        m_modelSprite.setScale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }

    Platform_temporary::Platform_temporary(shared_ptr<logic::Subject>& subject) : Platform(subject) {
        createSprite("../Sprites/Temporary_platforms.png");
        m_modelSprite.setScale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }
}