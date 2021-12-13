/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_ENTITYVIEW_H
#define DOODLE_JUMP_ENTITYVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Logic_libary/Observer.h"
#include "../../src/Exceptions.h"
#include "../Game_Representation/Window.h"
#include "../Logic_libary/Camera.h"
#include "../Logic_libary/EntityModel.h"
#include "../Logic_libary/Player.h"
#include "../Logic_libary/BG_Tile.h"
#include "../Logic_libary/Bonus.h"
#include "../Logic_libary/Platform.h"

using namespace std;

namespace representation {
class EntityView : public logic::Observer{
        sf::Sprite m_modelSprite;
        sf::Texture m_modelTexture; //* Toevoegen anders raakt texture kwijt en krijg je white square*/
        float m_width;
        float m_height;
        shared_ptr<logic::EntityModel> m_entityModel;

    protected:

        EntityView();

        void createSprite(const string& filepath);

    public:

        EntityView(float width, float height, string &image);

        void update() override;

        /**
        * Function: setSprite(sf::Sprite sprite)
        * geeft een sprite aan de entity.
        * @param sprite: is een sf::Sprite.
        */
        void setSprite(sf::Sprite& sprite);

        /**
         * Function: setTexture(sf::Texture texture)
         * Geeft een texture aan de entity.
         * @param texture: is een sf::Texture.
         */
        void setTexture(sf::Texture& texture);

        /**
        * Function: setheight(float height)
        * Geeft de entity een hoogte.
        * @param height: is een float.
        */
        void setHeight(float height);

        /**
         * Function: setWidth(float width)
         * Geeft de entity een breedte.
         * @param width: is een float.
         */
        void setWidth(float width);

        void setEntityModel(shared_ptr<logic::Player_L>& player);

        void setEntityModel(shared_ptr<logic::Platform_L>& platform);

        void setEntityModel(shared_ptr<logic::Bonus_L>& bonus);

        void setEntityModel(shared_ptr<logic::BG_Tile_L>& bg_tile);

        /**
        * Function: getSprite()
        * geeft de sprite van de entity.
        */
        sf::Sprite& getSprite();

        /**
         * Function: getTexture()
         * Geeft de texture van de entity.
         */
        sf::Texture& getTexture();

        /**
         * Function: getHeight()
         * Geeft de hoogte van de entity terug.
         * @return float
         */
        float getHeight() const;

        /**
         * Function: getWidth()
         * Geeft de breedte van de entity terug.
         * @return float
         */
        float getWidth() const;

        shared_ptr<logic::EntityModel> getEntityModel();


    };

}



#endif //DOODLE_JUMP_ENTITYVIEW_H
