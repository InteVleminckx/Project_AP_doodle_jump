//
// Created by inte on 11/18/21.
//

#include "Player.h"

namespace representation {


    Player::Player() {}

    Player::Player(logic::Subject& subject)
    {
        m_subject = subject;
        createSprite("../Sprites/Doodle_player.png");
    }

}