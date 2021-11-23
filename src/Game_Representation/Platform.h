//
// Created by inte on 11/23/21.
//

#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include <iostream>
#include "Entity_View.h"
#include "../Logic_libary/Platform.h"

using namespace std;

namespace representation {
    class Platform : public Entity_View{
    public:
        Platform();
        Platform(logic::Subject& subject);

        void update() override;

    };

    class Platform_static : public Platform {
    public:
        Platform_static(logic::Subject& subject);
    };

    class Platform_vertical : public Platform {
    public:
        Platform_vertical(logic::Subject& subject);
    };

    class Platform_horizontal : public Platform {
    public:
        Platform_horizontal(logic::Subject& subject);
    };

    class Platform_temporary : public Platform {
    public:
        Platform_temporary(logic::Subject& subject);
    };

}

#endif //DOODLE_JUMP_PLATFORM_H
