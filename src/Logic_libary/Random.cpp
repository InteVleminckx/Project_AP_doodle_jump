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

        int number = rand() % 101;

        if (number < 70) return Static;
        if (number < 80) return Vertical;
        if (number < 90) return Horizontal;
        return Temporary;
    }

    _Bonus Random::getBonusType() {
        //ToDo: dit nog afstellen op score, in het begin veel meer kans op bonussen

        int number = rand() % 2;

        if (number == 0) return Spring;
        return Rocket;
    }

    bool Random::createPlatform() {
        //ToDo: dit nog afstellen op score, in het begin veel meer kans op platforms

        int number = rand() % 10;

        if (number < 8) return true;
        return false;

    }

    float Random::giveRandomX(float leftBound, float rightBound) {

        //we genereren een random nummer tussen 1 en 50 dit als we dan de right bound hier door delen krijgen we een float
        int number = rand() % 5;
        number+=1; //om 0 te voorkomen

        return leftBound + (rightBound/number);


    }
}