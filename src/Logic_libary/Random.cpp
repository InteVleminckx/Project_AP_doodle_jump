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

        m_difficultyNiveau = 1;

        Reset();
    }

    Random::~Random() {}

    void Random::Reset() { srand(time(0)); }

    PlatformType Random::getPlatformType() {

        //ToDo: dit nog afstellen op score, in het begin veel meer kans op static platforms
        //Nadien eigenlijk zien wat score is en zo meer kans geven op andere soorten platforms

        int number = rand() % 101;

        if (number < 70) return Static_;
        if (number < 80) return Vertical_;
        if (number < 90) return Horizontal_;
        return Temporary_;
    }

    BonusType Random::getBonusType() {
        //ToDo: dit nog afstellen op score, in het begin veel meer kans op bonussen

        int number = rand() % 2;

        if (number == 0) return Spring_;
        return Rocket_;
    }

    bool Random::createPlatform(float prevPlatform, float possiblePlatform) {
        //ToDo: dit nog afstellen op score, in het begin veel meer kans op platforms

        //het is zo dat we minstens om de zoveel keer we deze functie hebben aangeroepen toch zeker 1 platform moeten creëeren
        //Want anders als het moeilijker en moeilijker wordt dan gaan we misschien niet meer aan het volgende programma geraken.

        //Als we zeggen dat we maximaal 15 platforms willen genereren op 1 window
        //Dan zeggen we dat bij niveau 1 de kans op platforms 14/15 is
        //bij niveau 2 dan 13/14 enzovoort tot bij niveau 10 hebben we dan 5/15
        //Wat zegt dat de kans dat we telkens een platform willen genereren 33% is

        int maxPlatforms = 15.f;
        int maxPlatsNiveau = maxPlatforms - m_difficultyNiveau;
        float chance = (float)maxPlatsNiveau / (float) maxPlatforms;

        //bron: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0, 1);

        if (chance > dis(gen) || (possiblePlatform - prevPlatform > 0.5f))
        {
            return true;
        }


        return false;

    }

    float Random::giveRandomX(float leftBound, float rightBound) {

        //bron: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(leftBound, rightBound);
        return dis(gen);

    }

    bool Random::createBonus() {
        //ToDo: dit nog afstellen op score

        int number = rand() % 10;

        if (number > 8) return true;
        return false;
    }

    void Random::refreshDifficulty(int score) {

        int possibleDifficulty = ceil(score / 10000);

        //We zetten de max moeilijkheidsgraad op 10
        if (possibleDifficulty > 10) return;

        //als de moeilijkheidsgraad kleiner is dan de graad die het kan worden wordt het dit.
        if (m_difficultyNiveau < possibleDifficulty) {
            m_difficultyNiveau = possibleDifficulty;
            cout << m_difficultyNiveau << endl;
        }

    }
}