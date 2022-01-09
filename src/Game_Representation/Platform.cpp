#include "Platform.h"

namespace representation {

Platform::Platform() = default;

Platform::Platform(shared_ptr<logic::Platform_L> platform, string& image)
    : EntityView(platform->getWidth(), platform->getHeight(), image)
{
        ControllingPointers::control(platform, "Platform",
                                     "Platform(shared_ptr<logic::Platform_L> platform, string& image)");
        setEntityModel(move(platform));
}

Platform_static::Platform_static(shared_ptr<logic::Platform_L> platform, string image) : Platform(move(platform), image)
{
}

Platform_vertical::Platform_vertical(shared_ptr<logic::Platform_L> platform, string image)
    : Platform(move(platform), image)
{
}

Platform_horizontal::Platform_horizontal(shared_ptr<logic::Platform_L> platform, string image)
    : Platform(move(platform), image)
{
}

Platform_temporary::Platform_temporary(shared_ptr<logic::Platform_L> platform, string image)
    : Platform(move(platform), image)
{
}

Platform::~Platform() = default;

Platform_static::~Platform_static() = default;

Platform_vertical::~Platform_vertical() = default;

Platform_horizontal::~Platform_horizontal() = default;

Platform_temporary::~Platform_temporary() = default;
} // namespace representation