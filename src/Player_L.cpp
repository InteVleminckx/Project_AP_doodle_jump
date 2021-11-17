#include "Player_L.h"


void Player_L::gravity() {setY(getY() - getVelocityY());}

void Player_L::moveRight() {setX(getX() + getVelocityX());}

void Player_L::moveLeft() {setX(getX() - getVelocityX());}


