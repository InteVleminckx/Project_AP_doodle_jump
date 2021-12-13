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
        float m_startPositionY{};
    protected:

        /**
         * Is een constructor.
         */
        Platform_L();

    public:

        Platform_L(float posX, float posY, float width, float height);

        /**
         * Zet temporary op true of false naar gelang zijn staat.
         * @param temporary: is een bool.
         */
        void setTemporary(bool temporary);

        /**
         * Zegt of een platform temporary is of niet.
         * @return: een bool.
         */
        bool isTemporary();

        void setStartPostionY(float y);

        float getStartPositionY();

        virtual void movePlatform() {};

        virtual void changeDirection() {};

    };

    class Platform_L_static : public  Platform_L {

        /**
         * Is een constructor.
         */
        Platform_L_static();

    public:

        Platform_L_static(float posX, float posY, float width, float height);
    };

    class Platform_L_vertical : public  Platform_L {

        /**
         * Is een constructor.
         */
        Platform_L_vertical();

    public:

        Platform_L_vertical(float posX, float posY, float width, float height);

        void movePlatform() override;

        void changeDirection() override;
    };

    class Platform_L_horizontal : public  Platform_L {

        /**
         * Is een constructor.
         */
        Platform_L_horizontal();

    public:

        Platform_L_horizontal(float posX, float posY, float width, float height);

        void movePlatform() override;

        void changeDirection() override;
    };

    class Platform_L_temporary : public  Platform_L {

        /**
         * Is een constructor.
         */
        Platform_L_temporary();

    public:

        Platform_L_temporary(float posX, float posY, float width, float height);
    };
}



#endif //DOODLE_JUMP_PLATFORM_L_H
