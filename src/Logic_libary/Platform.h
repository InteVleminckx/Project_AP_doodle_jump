/****************************************************************************************************
 * @author Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Platform_L
 * @BaseClass EntityModel
 * @SubClasses none
 * @Namespace logic
 * @brief Is een subclass van EntityModel. Het bevat alle informatie over de Platform.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_PLATFORM_L_H
#define DOODLE_JUMP_PLATFORM_L_H

#include <iostream>
#include "EntityModel.h"

using namespace std;

namespace logic {
    class Platform_L : public EntityModel {

        /****************************************************************************************************
         * @brief Zegt of het platform een temporary platform is of niet.
         * @type bool
         * @var m_temporary
         ****************************************************************************************************/
        bool m_temporary = false;

        /****************************************************************************************************
         * @brief Is de startpositie in de y richting van het platform.
         * @type float
         * @var m_startPositionY
         ****************************************************************************************************/
        float m_startPositionY{};

    public:

        /****************************************************************************************************
         * @function Platform_L(float posX, float posY, float width, float height)
         * @brief De construct van Platform_L waar de argumenten hiervan de informatie over de Platform zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Platform.
         * @param height: is een float, het is de hoogte van de Platform.
         ****************************************************************************************************/
        Platform_L(float posX, float posY, float width, float height);

        /****************************************************************************************************
         * @function void setTemporary(bool temporary)
         * @brief Zet temporary op true of false naar gelang zijn staat.
         * @param temporary: is een bool die m_temporary instelt.
         ****************************************************************************************************/
        void setTemporary(bool temporary);

        /****************************************************************************************************
         * @function bool isTemporary()
         * @brief Zet de startpositie van het platform.
         * @param y: is een float, wat de startpositie wordt.
         ****************************************************************************************************/
        void setStartPostionY(float y);

        /****************************************************************************************************
         * @function bool isTemporary()
         * @brief Zegt of een platform temporary is of niet.
         * @return een bool, wat de informatie bevat dat een platorm temporary is of niet.
         ****************************************************************************************************/
        bool isTemporary();

        /****************************************************************************************************
         * @function float getStartPositionY()
         * @brief Geeft de startpositie in de y richting terug.
         * @return is een float, wat de startpositie in de y richting is.
         ****************************************************************************************************/
        float getStartPositionY();

        /****************************************************************************************************
         * @function virtual void movePlatfrom()
         * @brief Beweegt het platform. Is een pure virtual void function.
         ****************************************************************************************************/
        virtual void movePlatform() = 0;

        /****************************************************************************************************
         * @function virtual void changeDirection()
         * @brief Veranderd de bewegingsrichting van het platform. Is een pure virtual void function.
         ****************************************************************************************************/
        virtual void changeDirection() = 0;

        ~Platform_L() override;

    };

    class Platform_L_static : public  Platform_L {

    public:

        /****************************************************************************************************
         * @function Platform_L_static(float posX, float posY, float width, float height)
         * @brief De construct van Platform_L_static waar de argumenten hiervan de informatie over de Platform_static zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Platform_static.
         * @param height: is een float, het is de hoogte van de Platform_static.
         ****************************************************************************************************/
        Platform_L_static(float posX, float posY, float width, float height);

        /****************************************************************************************************
         * @function virtual void movePlatfrom() override
         * @brief De functie is niet nodig maar moet wel override worden omdat deze in de base class pure virtual is.
         ****************************************************************************************************/
        void movePlatform() override;

        /****************************************************************************************************
         * @function virtual void changeDirection() override
         * @brief De functie is niet nodig maar moet wel override worden omdat deze in de base class pure virtual is.
         ****************************************************************************************************/
        void changeDirection() override;

        ~Platform_L_static() override;

    };

    class Platform_L_vertical : public  Platform_L {

    public:

        /****************************************************************************************************
         * @function Platform_L_vertical(float posX, float posY, float width, float height)
         * @brief De construct van Platform_L_vertical waar de argumenten hiervan de informatie over de Platform_vertical zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Platform_vertical.
         * @param height: is een float, het is de hoogte van de Platform_vertical.
         ****************************************************************************************************/
        Platform_L_vertical(float posX, float posY, float width, float height);

        /****************************************************************************************************
         * @function virtual void movePlatfrom() override
         * @brief Beweegt het platform in de verticale richting van boven naar onder en omgekeerd.
         ****************************************************************************************************/
        void movePlatform() override;

        /****************************************************************************************************
         * @function virtual void changeDirection() override
         * @brief Veranderd de bewegingsrichting van het platform.
         ****************************************************************************************************/
        void changeDirection() override;

        ~Platform_L_vertical() override;
    };

    class Platform_L_horizontal : public  Platform_L {

    public:

        /****************************************************************************************************
         * @function Platform_L_horizontal(float posX, float posY, float width, float height)
         * @brief De construct van Platform_L_horizontal waar de argumenten hiervan de informatie over de Platform_horizontal zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Platform_horizontal.
         * @param height: is een float, het is de hoogte van de Platform_horizontal.
         ****************************************************************************************************/
        Platform_L_horizontal(float posX, float posY, float width, float height);

        /****************************************************************************************************
         * @function virtual void movePlatfrom() override
         * @brief Beweegt het platform in de horizontale richting van links naar rechts en omgekeerd.
         ****************************************************************************************************/
        void movePlatform() override;

        /****************************************************************************************************
         * @function virtual void changeDirection() override
         * @brief Veranderd de bewegingsrichting van het platform.
         ****************************************************************************************************/
        void changeDirection() override;

        ~Platform_L_horizontal() override;
    };

    class Platform_L_temporary : public  Platform_L {

    public:

        /****************************************************************************************************
         * @function Platform_L_temporary(float posX, float posY, float width, float height)
         * @brief De construct van Platform_L_temporary waar de argumenten hiervan de informatie over de Platform_temporary zijn.
         * @param posX: is een float, het is de beginpositie in de x richting.
         * @param posY: is een float, het is de beginpositie in de y riching.
         * @param width: is een float, het is de breedte van de Platform_temporary.
         * @param height: is een float, het is de hoogte van de Platform_temporary.
         ****************************************************************************************************/
        Platform_L_temporary(float posX, float posY, float width, float height);

        /****************************************************************************************************
         * @function virtual void movePlatfrom() override
         * @brief De functie is niet nodig maar moet wel override worden omdat deze in de base class pure virtual is.
         ****************************************************************************************************/
         void movePlatform() override;

        /****************************************************************************************************
         * @function virtual void changeDirection() override
         * @brief De functie is niet nodig maar moet wel override worden omdat deze in de base class pure virtual is.
         ****************************************************************************************************/
        void changeDirection() override;

        ~Platform_L_temporary() override;
    };
}



#endif //DOODLE_JUMP_PLATFORM_L_H
