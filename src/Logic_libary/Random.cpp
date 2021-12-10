#include "Random.h"

namespace logic {
    Random* Random::s_instance = nullptr;

    Random* Random::Instance() {
        if (s_instance == nullptr)
            s_instance = new Random;
        return s_instance;
    }

    void Random::Release() {
        delete s_instance;
        s_instance = nullptr;
    }

    Random::Random() {
        Reset();
    }

    Random::~Random() {}

    void Random::Reset() { srand(time(0)); }

    _Platform Random::getPlatformType() {

        //ToDo: dit nog afstellen op score, in het begin veel meer kans op static platforms
        //Nadien eigenlijk zien wat score is en zo meer kans geven op andere soorten platforms

        int number = rand() % 4;

        switch (number) {
            case 0:
                return Static;
            case 1:
                return Vertical;
            case 2:
                return Horizontal;
            case 3:
                return Temporary;
        }

        return Static;
    }
}