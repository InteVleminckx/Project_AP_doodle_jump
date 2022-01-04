/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Camera
 * @BaseClass none
 * @SubClasses none
 * @Namespace logic
 * @brief Is een singleton implementatie.
 ****************************************************************************************************/


#ifndef DOODLE_JUMP_CAMERA_H
#define DOODLE_JUMP_CAMERA_H

#include <iostream>
#include <cmath>

using namespace std;

struct projectedPixels : std::pair<float, float> { float &x = this->first; float &y = this->second; };

namespace logic {

    class Camera {
    /****************************************************************************************************
     * @privatesection
     ****************************************************************************************************/

        /****************************************************************************************************
         * @brief Een pointer naar het camera object.
         * @type static Camera*
         * @var m_instance
         ****************************************************************************************************/
        static Camera* s_instance;

        /****************************************************************************************************
         * @brief Zijn de hoogte en breedte van de camera scope.
         * @type int
         * @var m_width, m_height
         ****************************************************************************************************/
        int m_width, m_height;

        /****************************************************************************************************
         * @brief Is de offset waarmee de camera een projectie moet doen t.o.v. het logic coordinate system.
         * @type float
         * @var m_offset
         ****************************************************************************************************/
        float m_offset{};

        /****************************************************************************************************
         * @function Camera(int width, int height)
         * @brief Stelt de instellingen in voor een camera.
         * @param width: is een int wat de breedte van de camera scope wordt.
         * @param height: is een int wat de hoogte van de camera scope wordt.
         ****************************************************************************************************/
        Camera(int width, int height);

    /****************************************************************************************************
     * @publicsection
     ****************************************************************************************************/
    public:

        /****************************************************************************************************
         * @function static Camera* Instance(int width = 0, int height = 0)
         * @brief Geeft de camera terug, moest er nog geen bestaand wordt er 1 aangemaakt.
         * @param width: is een int wat de breedte van de camera scope wordt.
         * @param height: is een int wat de hoogte van de camera scope wordt.
         * @return static Camera* de camera.
         ****************************************************************************************************/
        static Camera* Instance(int width = 0, int height = 0);

        /****************************************************************************************************
         * @function static void Release()
         * @brief Verwijderd de pointer naar de camera.
         ****************************************************************************************************/
        static void Release();

        /****************************************************************************************************
         * @function projectedPixels projectToPixel(float x, float y)
         * @brief Verwijderd de pointer naar de window.
         * @param x: is een float, de logic x die geprojecteerd moet worden.
         * @param y: is een float, de logic y die geprojecteerd moet worden.
         * @return De geprojecteerde coördinaten.
         ****************************************************************************************************/
        projectedPixels projectToPixel(float x, float y);

        /****************************************************************************************************
         * @function int reproduceScore(float score)
         * @brief Zet de hoogte om van de player naar een ronde score.
         * @param score: de "huidige" score.
         * @return De nieuwe omgezette score als een integer.
         ****************************************************************************************************/
        int reproduceScore(float score);

        /****************************************************************************************************
         * @function int getCameraWidth()
         * @brief Geeft de breedte van de camera terug.
         * @return is een integer, wat de breedte van de camera bevat
         ****************************************************************************************************/
        int getCameraWidth();

        /****************************************************************************************************
         * @function int getCameraHeight()
         * @brief Geeft de hoogte van de camera terug.
         * @return is een integer, wat de hoogte van de camera bevat
         ****************************************************************************************************/
        int getCameraHeight();

        /****************************************************************************************************
         * @function float getOffset()
         * @brief Geeft de offset van de camera terug.
         * @return is een float, wat de m_offset is.
         ****************************************************************************************************/
        float getOffset();

        /****************************************************************************************************
         * @function bool setOffset(float y)
         * @brief Veranderd de offset door deze gelijk te stellen aan het argument dat meegeven wordt.
         * @param y: is een float, wat de nieuwe offset zal worden.
         * @return Een boolean die zegt of de offset gewijzigd is.
         ****************************************************************************************************/
        bool setOffset(float y);

    /****************************************************************************************************
     * @privatesection
     ****************************************************************************************************/
    private:

        /****************************************************************************************************
         * @function ~Camera()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Camera();

    };
}


#endif //DOODLE_JUMP_CAMERA_H
