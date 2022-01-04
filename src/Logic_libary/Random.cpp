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

    void Random::Reset() { srand(time(0)); }

    PlatformType Random::getPlatformType() {


        /**
         * Chances per niveau:
         * Niveau	static	hori	verti	temp	total	chances:	static	hori	verti	temp
            1	    18	    2	    0	    0	    20		            90,00%	10,00%	0,00%	0,00%
            2	    16,5	2,5	    0,4	    0,6	    20		            82,50%	12,50%	2,00%	3,00%
            3	    15	    3	    0,8	    1,2	    20		            75,00%	15,00%	4,00%	6,00%
            4	    13,5	3,5	    1,2	    1,8	    20		            67,50%	17,50%	6,00%	9,00%
            5	    12	    4	    1,6	    2,4	    20		            60,00%	20,00%	8,00%	12,00%
            6	    10,5	4,5	    2	    3	    20		            52,50%	22,50%	10,00%	15,00%
            7	    9	    5	    2,4	    3,6	    20		            45,00%	25,00%	12,00%	18,00%
            8	    7,5	    5,5	    2,8	    4,2	    20		            37,50%	27,50%	14,00%	21,00%
            9	    6	    6	    3,2	    4,8	    20		            30,00%	30,00%	16,00%	24,00%
            10	    4,5	    6,5	    3,6	    5,4	    20		            22,50%	32,50%	18,00%	27,00%
         */


        float staticChance = ((18.f) - (float) (1.5 * (m_difficultyNiveau-1))) / 20;
        float horizontalChance = ((2.f) + (float) (0.5 * (m_difficultyNiveau-1))) / 20;
        float verticalChance = ((0.f) + (float) (0.4 * (m_difficultyNiveau-1))) / 20;

        //bron: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0, 1);


        if (staticChance > dis(gen)) return Static_;
        else if (staticChance + horizontalChance > dis(gen)) return Horizontal_;
        else if (staticChance + horizontalChance + verticalChance > dis(gen)) return Vertical_;
        else return Temporary_;
    }

    BonusType Random::getBonusType() {

        // De kans op een Spring is groter dan de kans op een Rocket

        int number = rand() % 5;

        if (number < 4) return Spring_;
        return Rocket_;
    }

    bool Random::createPlatform(float prevPlatform, float possiblePlatform) {
        //het is zo dat we minstens om de zoveel keer we deze functie hebben aangeroepen toch zeker 1 platform moeten creëeren
        //Want anders als het moeilijker en moeilijker wordt dan gaan we misschien niet meer aan het volgende programma geraken.

        /**
         * platform spawn chance:
            Niveau	max plats: 	11	per niveau	chance
            1			            10	        90,91%
            2			            9	        81,82%
            3			            8	        72,73%
            4			            7	        63,64%
            5			            6	        54,55%
            6			            5	        45,45%
            7			            4	        36,36%
            8			            3	        27,27%
            9			            2	        18,18%
            10			            1	        9,09%
         */

        int maxPlatforms = 11.f;
        int maxPlatsNiveau = maxPlatforms - m_difficultyNiveau;
        float chance = (float)maxPlatsNiveau / (float) maxPlatforms;

        //bron: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0, 1);

        if (chance >= dis(gen) || (possiblePlatform - prevPlatform > 0.5f)) return true;
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
        //In het begin kunnen we zeggen dat de kans op een Bonus 19/50 is
        //Op het moeilijkste niveau kunnen we zeggen dat de kans dan 1/20 is.

        /**
         * Niveau	chance
            1	    38,00%
            2	    34,00%
            3	    30,00%
            4	    26,00%
            5	    22,00%
            6	    18,00%
            7	    14,00%
            8	    10,00%
            9	    6,00%
            10	    2,00%
         */

        int noemerChance = 50;
        int tellerChance = 20;
        int difficultyTeller = tellerChance - (2*m_difficultyNiveau) + 1;

        float chance = (float) difficultyTeller / (float) noemerChance;

        //bron: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0, 1);

        if (chance >= dis(gen)) return true;
        return false;
    }

    void Random::refreshDifficulty(int score) {

        int possibleDifficulty = ceil(score / 10000);

        //We zetten de max moeilijkheidsgraad op 10
        if (possibleDifficulty > 10) return;

        //als de moeilijkheidsgraad kleiner is dan de graad die het kan worden wordt het dit.
        if (m_difficultyNiveau < possibleDifficulty) {
            m_difficultyNiveau = possibleDifficulty;
        }

    }

    Random::~Random() = default;
}