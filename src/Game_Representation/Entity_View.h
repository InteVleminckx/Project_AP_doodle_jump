/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_ENTITY_VIEW_H
#define DOODLE_JUMP_ENTITY_VIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Logic_libary/Observer.h"
#include "../../src/Exceptions.h"
#include "../Game_Representation/Window.h"

using namespace std;

namespace representation {
class Entity_View : public logic::Observer{

    protected:

        sf::Sprite m_modelSprite;
        sf::Texture m_modelTexture; //* Toevoegen anders raakt texture kwijt en krijg je white square*/

        Entity_View();

        void createSprite(const string& filepath);

    public:

        Entity_View(shared_ptr<logic::Subject>& subject);

        sf::Sprite getSprite();

    };

}



#endif //DOODLE_JUMP_ENTITY_VIEW_H
