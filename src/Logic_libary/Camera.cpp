#include "Camera.h"

namespace logic {

    Camera* Camera::s_instance = nullptr;

    Camera* Camera::Instance(int width, int height) {
        if (s_instance == nullptr)
            s_instance = new Camera(width, height);
        return s_instance;
    }

    void Camera::Release() {
        delete s_instance;
        s_instance = nullptr;
    }

    Camera::Camera(int width, int height) : m_height(height), m_width(width){}

    Camera::~Camera() {}

    projectedPixels Camera::projectToPixel(float x, float y) {

        /*
         * Als het logic van -1 tot 1 gaat en de camera van 0 tot width
         * Dan betekent dat in logic 0 == in camera width/2
         * Dus als we -1 hebben in logic krijgen we camera width/2 - camera width/2 wat 0 geeft
         * Als we 1 hebben in logic krijgen we camera width/2 + camera width/2 wat width geeft
         *
         * Dit kunnen we dan ook zo interpreteren voor de hoogte
         */
        projectedPixels pixels;
//        pixels.x = (m_width/2 + (x * m_width/2));
        pixels.x = x*m_width;
        pixels.y = m_height - (m_height/2 + (y * m_height/2) - (m_offset*m_height/2));

        return pixels;

    }

    int Camera::getCameraWidth() {return m_width;}

    int Camera::getCameraHeight() {return m_width;}

    void Camera::setOffset(float y) {
        if (y >= 0 && y > m_offset) m_offset = y;
    }

    int Camera::reproduceScore(float score) {

        return ceil(score*m_height);

    }

    float Camera::getOffset() {
        return m_offset;
    }
}
