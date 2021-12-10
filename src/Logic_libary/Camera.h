/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */


#ifndef DOODLE_JUMP_CAMERA_H
#define DOODLE_JUMP_CAMERA_H

#include <iostream>


using namespace std;

struct projectedPixels : std::pair<float, float> { float &x = this->first; float &y = this->second; };

namespace logic {
    class Camera {

        static Camera* s_instance;
        int m_width, m_height;
        float m_offset{};

    public:

        static Camera* Instance(int width = 0, int height = 0);

        static void Release();

        projectedPixels projectToPixel(float x, float y);

        bool visibleInView(float x, float y);

        int getCameraWidth();

        int getCameraHeight();

        void setOffset(float y){
            if (y >= 0 && y > m_offset)
            {
                m_offset = y;
            }
        }

    private:
        Camera(int width, int height);

        ~Camera();

    };
}


#endif //DOODLE_JUMP_CAMERA_H
