//
// Created by inte on 11/4/21.
//

#ifndef DOODLE_JUMP_PLAYER_H
#define DOODLE_JUMP_PLAYER_H

#include <iostream>
#include "Entity.h"

using namespace std;

class Player : public Entity {
    double m_velocityX;
    double m_velocityY;

public:

    Player();

    /**
     * Verplaats de speler in de x richting.
     * @param right: bool, deze bepaalt of de speler rechts of links moet gaan
     */
    void move_playerX(bool right);


};


#endif //DOODLE_JUMP_PLAYER_H
