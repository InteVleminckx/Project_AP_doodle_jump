/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Score_L
 * @BaseClass Observer
 * @SubClasses none
 * @Namespace Score_L
 * @brief Bevat de score van de game, deze wordt geobserveerd aan de hand van de player.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_SCORE_L_H
#define DOODLE_JUMP_SCORE_L_H
#include "Observer.h"
#include "Player.h"
#include <fstream>
#include "../json.hpp"
#include "ControllingPointers.h"

using json = nlohmann::json;


namespace logic {

    class Random;

    class Score_L : public Observer{

        /****************************************************************************************************
         * @brief Is de score van het spel, wat op nul begint.
         * @type int
         * @var m_score
         ****************************************************************************************************/
        int m_score{};

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
         * @param player shared_ptr naar een player die de data member zal initialiseren.
         ****************************************************************************************************/
        Score_L(shared_ptr<Player_L> player);


        /****************************************************************************************************
         * @function void setScore(float score)
         * @brief Het zal een score binnen krijgen in een float getal en zal deze toekennen aan m_score, maar ook
         * ineens omzetten naar een gereproduceerde score.
         * @param score: Is eeen float
         ****************************************************************************************************/
        void setScore(float score);

        /****************************************************************************************************
         * @function void update() override
         * @brief Zal de update functie overschrijven zodat de score altijd geupdate worden want hier moet niet
         * een afbeelding getoont worden maar de text van de score wordt wel geupdate.
         ****************************************************************************************************/
        void update() override;

        /****************************************************************************************************
         * @function void updateScore()
         * @brief Zal score aanpassen als dit nodig is.
         ****************************************************************************************************/
        void updateScore();

        /****************************************************************************************************
         * @function int getScore()
         * @brief Zal de score teruggeven.
         * @return Is een int wat de score is.
         ****************************************************************************************************/
        int getScore();

        /****************************************************************************************************
         * @function shared_ptr<Player_L> getPlayer()
         * @brief Zal de player teruggeven.
         * @return Is een shared_ptr<Player_L> wat een pointer naar de player zal zijn.
         ****************************************************************************************************/
        shared_ptr<Player_L> getPlayer();

        void saveScore();

        ~Score_L() override;

    };
}


#endif //DOODLE_JUMP_SCORE_L_H
