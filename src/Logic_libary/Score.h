/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Score
 * @BaseClass Observer
 * @SubClasses none
 * @Namespace logic
 * @brief Bevat de score van de game, deze wordt geobserveerd aan de hand van de player.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_SCORE_H
#define DOODLE_JUMP_SCORE_H
#include "Observer.h"
#include "Player.h"


namespace logic {

    class Score : public Observer{

        /****************************************************************************************************
         * @brief Is de score van het spel, wat op nul begint.
         * @type float
         * @var m_score
         ****************************************************************************************************/
        float m_score{};

        /****************************************************************************************************
         * @brief Een shared_ptr naar een Player_L.
         * @type shared_ptr<Player_L>
         * @var m_player
         ****************************************************************************************************/
        shared_ptr<Player_L> m_player;


    public:

        /****************************************************************************************************
         * @function Score(shared_ptr<Player_L>& player)
         * @brief Een constructor die de player initialiseerd.
         * @param Een shared_ptr naar een player die de data member zal initialiseren.
         ****************************************************************************************************/
        Score(shared_ptr<Player_L>& player);

        /****************************************************************************************************
         * @function void update() override
         * @brief Zal de update functie overschrijven zodat de score altijd geupdate worden want hier moet niet
         * een afbeelding getoont worden zoals bij andere observers.
         ****************************************************************************************************/
        void update() override;

        /****************************************************************************************************
         * @function float getScore()
         * @brief Zal de score teruggeven.
         * @return Is een float wat de score is.
         ****************************************************************************************************/
        float getScore();

    };
}


#endif //DOODLE_JUMP_SCORE_H
