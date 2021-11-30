//
// Created by inte on 11/20/21.
//

#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Logic_libary/World.h"
#include "Window.h"
#include "PlayerFactory.h"
#include "PlatformFactory.h"


using namespace std;

namespace representation {
    class Game {
        logic::World m_world;
        float m_frameRate;


    public:
        Game();
        void beginGame();
        void stopGame();
    };
}


#endif //DOODLE_JUMP_GAME_H
