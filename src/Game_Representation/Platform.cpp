//
// Created by inte on 11/23/21.
//

#include "Platform.h"

namespace representation {

    Platform::Platform() = default;

    Platform::Platform(shared_ptr<logic::Subject>& subject) {m_subject = subject;}

    void Platform::update() {
        representation::Window* window = representation::Window::Instance();
//        m_modelSprite.setPosition(((logic::Platform_L* ) m_subject)->getX(), ((logic::Platform_L* ) m_subject)->getY());
        window->getWindow()->draw(m_modelSprite);
    }

    Platform_static::Platform_static(shared_ptr<logic::Subject>& subject) {
        m_subject = subject;
        createSprite("../Sprites/Static_platforms.png");
    }

    Platform_vertical::Platform_vertical(shared_ptr<logic::Subject>& subject) {
        m_subject = subject;
        createSprite("../Sprites/Vertical_platforms.png");
    }

    Platform_horizontal::Platform_horizontal(shared_ptr<logic::Subject>& subject) {
        m_subject = subject;
        createSprite("../Sprites/Horizontal_platforms.png");
    }

    Platform_temporary::Platform_temporary(shared_ptr<logic::Subject>& subject) {
        m_subject = subject;
        createSprite("../Sprites/Temporary_platforms.png");
    }
}