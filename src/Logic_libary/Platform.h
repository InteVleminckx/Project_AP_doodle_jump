/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_PLATFORM_L_H
#define DOODLE_JUMP_PLATFORM_L_H

#include <iostream>
#include "EntityModel.h"

using namespace std;

namespace logic {
    class Platform_L : public EntityModel {

        bool m_temporary = false;
        bool m_vertical = false;
        bool m_horizontal = false;

    public:

        /**
         * Is een constructor.
         */
        Platform_L();

        /**
         * Zet temporary op true of false naar gelang zijn staat.
         * @param temporary: is een bool.
         */
        void setTemporary(bool temporary);

        /**
         * Zet vertical op true of false naar gelang zijn staat.
         * @param vertical: is een bool.
         */
        void setVertical(bool vertical);

        /**
         * Zet horizontal op true of false naar gelang zijn staat.
         * @param horizontal: is een bool.
         */
        void setHorizontal(bool horizontal);

        /**
         * Zegt of een platform temporary is of niet.
         * @return: een bool.
         */
        bool isTemporary() const;

        /**
         * Zegt of een platform vertical is of niet.
         * @return: een bool.
         */
        bool isVertical() const;

        /**
         * Zegt of een platform horizontal is of niet.
         * @return: een bool.
         */
        bool isHorizontal() const;

    };

    class Platform_L_static : public  Platform_L {

    public:

        /**
         * Is een constructor.
         */
        Platform_L_static();

    };

    class Platform_L_vertical : public  Platform_L {

    public:

        /**
         * Is een constructor.
         */
        Platform_L_vertical();

    };

    class Platform_L_horizontal : public  Platform_L {

    public:

        /**
         * Is een constructor.
         */
        Platform_L_horizontal();

    };

    class Platform_L_temporary : public  Platform_L {

    public:

        /**
         * Is een constructor.
         */
        Platform_L_temporary();

    };
}



#endif //DOODLE_JUMP_PLATFORM_L_H
