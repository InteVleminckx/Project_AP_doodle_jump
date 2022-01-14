#include "Camera.h"

namespace logic {

Camera& Camera::Instance(int width, int height)
{
        static Camera instance(width, height);
        return instance;
}

Camera::Camera(int width, int height) : m_height(height), m_width(width) {}

projectedPixels Camera::projectToPixel(float x, float y) const
{

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
        pixels.x = x * m_width;
        pixels.y = m_height - (m_height / 2 + (y * m_height / 2) - (m_offset * m_height / 2));

        return pixels;
}

int Camera::getCameraWidth() const { return m_width; }

int Camera::getCameraHeight() const { return m_width; }

bool Camera::setOffset(float y)
{
        if (y >= 0 && y > m_offset) {
                m_offset = y;
                return true;
        }
        return false;
}

int Camera::reproduceScore(float score) const { return ceil(score * m_height); }

float Camera::getOffset() const { return m_offset; }

void Camera::Reset() { m_offset = 0; }

Camera::~Camera() = default;
} // namespace logic
