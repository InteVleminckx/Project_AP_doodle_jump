#ifndef DOODLE_JUMP_RANDOM_H
#define DOODLE_JUMP_RANDOM_H

#include <iostream>
#include <time.h>
#include <random>
#include "EntityFactory.h"

using namespace std;

namespace logic {
    class Random {
        static Random* s_instance;

    public:

        static Random* Instance();

        static void Release();

        _Platform getPlatformType();

        void Reset();

    private:

        Random();

        ~Random();

    };
}


#endif //DOODLE_JUMP_RANDOM_H
