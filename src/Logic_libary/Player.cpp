#include "Player.h"

namespace logic {
    void Player::gravity() {setY(getY() - getVelocityY());}

    void Player::moveRight() {setX(getX() + getVelocityX());}

    void Player::moveLeft() {setX(getX() - getVelocityX());}

}


