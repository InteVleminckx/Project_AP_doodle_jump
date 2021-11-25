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

using namespace std;

namespace representation {
class EntityView : public logic::Observer{

    protected:

        sf::Sprite m_modelSprite;
        sf::Texture m_modelTexture; //* Toevoegen anders raakt texture kwijt en krijg je white square*/

        EntityView();

        void createSprite(const string& filepath);

    public:

        EntityView(shared_ptr<logic::Subject>& subject);

        sf::Sprite getSprite();

    };

}



#endif //DOODLE_JUMP_ENTITYVIEW_H
