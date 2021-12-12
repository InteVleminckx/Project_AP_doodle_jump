#include "BG_Tile.h"

namespace representation {

    BG_Tile::BG_Tile() = default;


    BG_Tile::BG_Tile(shared_ptr<logic::Subject> &subject) {
        m_width =  logic::Camera::Instance()->getCameraWidth() * subject->getWidth();
        m_height = logic::Camera::Instance()->getCameraHeight() * subject->getHeight();
        m_subject = subject;

        createSprite("../Sprites/BG_tile.png");
        m_modelSprite.setScale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);

    }
}