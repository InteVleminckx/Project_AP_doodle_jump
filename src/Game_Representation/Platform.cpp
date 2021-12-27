#include "Platform.h"

namespace representation {

    Platform::Platform() = default;

    Platform::Platform(shared_ptr<logic::Platform_L>& platform, string& image) : EntityView(platform->getWidth(), platform->getHeight(), image)
    {
        setEntityModel(platform);
    }

    Platform::~Platform() {cout << "delete Platform observer";}

    Platform_static::Platform_static(shared_ptr<logic::Platform_L>& platform, string image) : Platform(platform, image){}

    Platform_vertical::Platform_vertical(shared_ptr<logic::Platform_L>& platform, string image) : Platform(platform, image) {}

    Platform_vertical::~Platform_vertical() {
        cout << "delete Platform V observer";
    }

    Platform_horizontal::Platform_horizontal(shared_ptr<logic::Platform_L>& platform, string image) : Platform(platform, image) {}

    Platform_horizontal::~Platform_horizontal() {
        cout << "delete Platform H observer";
    }

    Platform_temporary::Platform_temporary(shared_ptr<logic::Platform_L>& platform, string image) : Platform(platform, image) {}

    Platform_temporary::~Platform_temporary() {
        cout << "delete Platform T observer";
    }
}