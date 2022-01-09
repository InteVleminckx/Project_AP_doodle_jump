/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum 09/01/2022
 * @Class Platform
 * @BaseClass EntityView
 * @SubClasses Platform_static, Platform_vertical, Platform_horizontal, PLatform_temporary
 * @Namespace representation
 * @brief Is een subclass van EntityView.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include "EntityView.h"
#include <iostream>

using namespace std;

namespace representation {
class Platform : public EntityView
{

        /****************************************************************************************************
         * @privatesection
         ****************************************************************************************************/

        /****************************************************************************************************
         * @function Platform()
         * @brief Default constructor.
         ****************************************************************************************************/
        Platform();

        /****************************************************************************************************
         * @publicsection
         ****************************************************************************************************/
public:
        /****************************************************************************************************
         * @function Platform(shared_ptr<logic::Platform_L>& platform, string& image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param platform: shared_ptr van een Platform_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Platform(shared_ptr<logic::Platform_L> platform, string& image);

        /****************************************************************************************************
         * @function ~Bonus()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Platform() override;
};

class Platform_static : public Platform
{

        /****************************************************************************************************
         * @publicsection
         ****************************************************************************************************/
public:
        /****************************************************************************************************
         * @function Platform_static(shared_ptr<logic::Platform_L>& platform, string image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param platform: shared_ptr van een Platform_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Platform_static(shared_ptr<logic::Platform_L> platform, string image);

        /****************************************************************************************************
         * @function ~Platform_static()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Platform_static() override;
};

class Platform_vertical : public Platform
{

        /****************************************************************************************************
         * @publicsection
         ****************************************************************************************************/
public:
        /****************************************************************************************************
         * @function Platform_vertical(shared_ptr<logic::Platform_L>& platform, string image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param platform: shared_ptr van een Platform_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Platform_vertical(shared_ptr<logic::Platform_L> platform, string image);

        /****************************************************************************************************
         * @function ~Platform_vertical()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Platform_vertical() override;
};

class Platform_horizontal : public Platform
{

        /****************************************************************************************************
         * @publicsection
         ****************************************************************************************************/
public:
        /****************************************************************************************************
         * @function Platform_horizontal(shared_ptr<logic::Platform_L>& platform, string image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param platform: shared_ptr van een Platform_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Platform_horizontal(shared_ptr<logic::Platform_L> platform, string image);

        /****************************************************************************************************
         * @function ~Platform_horizontal()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Platform_horizontal() override;
};

class Platform_temporary : public Platform
{

        /****************************************************************************************************
         * @publicsection
         ****************************************************************************************************/
public:
        /****************************************************************************************************
         * @function Platform_temporary(shared_ptr<logic::Platform_L>& platform, string image)
         * @brief Roept de constructor van EntityView aan en initialiseerd m_entityModel met een set functie.
         * @param platform: shared_ptr van een Platform_L wat een afleiding is van een EntityModel.
         * @param image: Een afbeelding die toegewijd wordt aan het object.
         ****************************************************************************************************/
        Platform_temporary(shared_ptr<logic::Platform_L> subject, string image);

        /****************************************************************************************************
         * @function ~Platform_temporary()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Platform_temporary() override;
};

} // namespace representation

#endif // DOODLE_JUMP_PLATFORM_H
