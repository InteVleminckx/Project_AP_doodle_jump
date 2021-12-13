#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include <iostream>
#include "EntityView.h"


using namespace std;

namespace representation {
    class Platform : public EntityView{
    protected:
        Platform();
    public:
        Platform(shared_ptr<logic::Platform_L>& platform, string& image);
    };

    class Platform_static : public Platform {
    public:
        Platform_static(shared_ptr<logic::Platform_L>& platform, string image);
    };

    class Platform_vertical : public Platform {
    public:
        Platform_vertical(shared_ptr<logic::Platform_L>& platform, string image);
    };

    class Platform_horizontal : public Platform {
    public:
        Platform_horizontal(shared_ptr<logic::Platform_L>& platform, string image);
    };

    class Platform_temporary : public Platform {
    public:
        Platform_temporary(shared_ptr<logic::Platform_L>& subject, string image);
    };

}

#endif //DOODLE_JUMP_PLATFORM_H
