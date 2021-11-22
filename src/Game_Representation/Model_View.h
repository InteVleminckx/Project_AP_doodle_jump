/**
 * Naam: Inte Vleminckx
 * Studentennummer: 20201844
 * Datum:
 * Version: V1.0
 * Description:
 */

#ifndef DOODLE_JUMP_MODEL_VIEW_H
#define DOODLE_JUMP_MODEL_VIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Logic_libary/Observer.h"
#include "../../src/Exceptions.h"

using namespace std;

namespace representation {
class Model_View : public logic::Observer{

    protected:

        sf::Sprite m_modelSprite;
        sf::Texture m_modelTexture; //* Toevoegen anders raakt texture kwijt en krijg je white square*/

        Model_View();

        void createSprite(const string& filepath);

    public:

        Model_View(logic::Subject& subject);

        sf::Sprite getSprite();

    };

}



#endif //DOODLE_JUMP_MODEL_VIEW_H
