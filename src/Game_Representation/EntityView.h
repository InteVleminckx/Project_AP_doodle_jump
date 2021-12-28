/****************************************************************************************************
 * @author Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class EntityView
 * @BaseClass Observer
 * @SubClasses Player, Platform, BG_Tile, Bonus
 * @Namespace representation
 * @brief Is een subclass van EntityView.
 ****************************************************************************************************/

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

        /****************************************************************************************************
         * @brief De sprite van een Entity.
         * @type sf::Sprite
         * @var m_modelSprite
         ****************************************************************************************************/
        sf::Sprite m_modelSprite;

        /****************************************************************************************************
         * @brief Het model van een Entity, moet bijgehouden worden anders verdwijnt deze.
         * @type sf::Texture
         * @var m_modelTexture
         ****************************************************************************************************/
        sf::Texture m_modelTexture;

        /****************************************************************************************************
         * @brief De breedte van de Entity.
         * @type float
         * @var m_width
         ****************************************************************************************************/
        float m_width;

        /****************************************************************************************************
         * @brief De hoogte van de Entity.
         * @type float
         * @var m_width
         ****************************************************************************************************/
        float m_height;

        /****************************************************************************************************
         * @brief Een shared pointer naar een entityModel dat een afleiding is van een subject.
         * @type shared_ptr<logic::EntityModel>
         * @var m_entityModel
         ****************************************************************************************************/
        shared_ptr<logic::EntityModel> m_entityModel;

    protected:

        /****************************************************************************************************
         * @function void createSprite(const string& filepath)
         * @brief Laadt een afbeelding in en die wordt gebruikt als texture voor de entity.
         * @param filepath: een const string& wat de filepath is naar de afbeelding.
         ****************************************************************************************************/
        void createSprite(const string& filepath);

    public:

        /****************************************************************************************************
         * @function EntityView(float width, float height, string &image)
         * @brief De hoogte en breedte worden hier aan de entity toegewijd. De sprite wordt hier ook gemaakt.
         * @param width: is een float wat de breedte van de entity wordt.
         * @param height: is een float wat de hoogte van de entity wordt.
         * @param filepath: is een const string& wat de filepath is naar de afbeelding.
         ****************************************************************************************************/
        EntityView(float width, float height, const string &filepath);

        /****************************************************************************************************
         * @function void update() override
         * @brief Update de entity zijn view naar zijn nieuwe huidige staat.
         ****************************************************************************************************/
        void update() override;

        /****************************************************************************************************
        * @function setSprite(sf::Sprite sprite)
        * @brief Geeft een sprite aan de entity.
        * @param sprite: is een sf::Sprite.
         ****************************************************************************************************/
        void setSprite(sf::Sprite& sprite);

        /****************************************************************************************************
         * @function setTexture(sf::Texture texture)
         * @brief Geeft een texture aan de entity.
         * @param texture: is een sf::Texture.
         ****************************************************************************************************/
        void setTexture(sf::Texture& texture);

        /****************************************************************************************************
        * @function setheight(float height)
        * @brief Geeft de entity een hoogte.
        * @param height: is een float.
         ****************************************************************************************************/
        void setHeight(float height);

        /****************************************************************************************************
         * @function setWidth(float width)
         * @brief Geeft de entity een breedte.
         * @param width: is een float.
         ****************************************************************************************************/
        void setWidth(float width);

        /****************************************************************************************************
         * @brief Initialiseerd de data member m_entityModel door deze gelijk te stellen aan een object van zijn subclass.
         * @function setEntityModel(shared_ptr<logic::Player_L>& player)
         * @param player: is een shared pointer van Player_L
         ****************************************************************************************************/
        void setEntityModel(shared_ptr<logic::Player_L> player);

        /****************************************************************************************************
         * @brief Initialiseerd de data member m_entityModel door deze gelijk te stellen aan een object van zijn subclass.
         * @function setEntityModel(shared_ptr<logic::Platform_L>& platform)
         * @param platform: is een shared pointer van Platform_L
         ****************************************************************************************************/
        void setEntityModel(shared_ptr<logic::Platform_L> platform);

        /****************************************************************************************************
         * @brief Initialiseerd de data member m_entityModel door deze gelijk te stellen aan een object van zijn subclass.
         * @function setEntityModel(shared_ptr<logic::Bonus_L>& bonus)
         * @param bonus: is een shared pointer van Bonus_L
         ****************************************************************************************************/
        void setEntityModel(shared_ptr<logic::Bonus_L> bonus);

        /****************************************************************************************************
         * @brief Initialiseerd de data member m_entityModel door deze gelijk te stellen aan een object van zijn subclass.
         * @function setEntityModel(shared_ptr<logic::BG_Tile_L>& bg_tile)
         * @param bg_tile: is een shared pointer van BG_Tile_L
         ****************************************************************************************************/
        void setEntityModel(shared_ptr<logic::BG_Tile_L> bg_tile);

        /****************************************************************************************************
        * @function getSprite()
        * @brief geeft de sprite van de entity.
         ****************************************************************************************************/
        sf::Sprite& getSprite();

        /****************************************************************************************************
         * @function getTexture()
         * @brief Geeft de texture van de entity.
         ****************************************************************************************************/
        sf::Texture& getTexture();

        /****************************************************************************************************
         * @function getHeight()
         * @brief Geeft de hoogte van de entity terug.
         * @return float
         ****************************************************************************************************/
        float getHeight() const;

        /****************************************************************************************************
         * @function getWidth()
         * @brief Geeft de breedte van de entity terug.
         * @return float
         ****************************************************************************************************/
        float getWidth() const;

//        /****************************************************************************************************
//         * @function getEntityModel()
//         * @brief Geeft de entityModel terug.
//         * @return shared_ptr<logic::EntityModel>
//         ****************************************************************************************************/
//        unique_ptr<logic::EntityModel> getEntityModel();

        ~EntityView() override;

    /****************************************************************************************************
     * @function EntityView()
     * @brief Default constructor
     ****************************************************************************************************/
    EntityView();


    };

}



#endif //DOODLE_JUMP_ENTITYVIEW_H
