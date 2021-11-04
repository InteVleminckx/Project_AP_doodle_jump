//
// Created by inte on 11/4/21.
//

#include "Player.h"

void Player::move_playerX(bool right) {(right) ? setX(getX() + m_velocityX) : setX(getX() - m_velocityX);}

