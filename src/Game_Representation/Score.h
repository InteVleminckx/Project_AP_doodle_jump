/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Score
 * @BaseClass Score_L
 * @SubClasses none
 * @Namespace representation
 * @brief Zal de score weergeven op het scherm.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_SCORE_H
#define DOODLE_JUMP_SCORE_H
#include "../Logic_libary/Score_L.h"

namespace representation {
    class Score : public logic::Score_L{
    /****************************************************************************************************
     * @privatesection
     ****************************************************************************************************/


        /****************************************************************************************************
         * @brief Is de text die de score displayed.
         * @type sf::Text
         * @var m_textScore
         ****************************************************************************************************/
        sf::Text m_textScore;

        /****************************************************************************************************
         * @brief Is de font die aan een text wordt toegewijd
         * @type sf::Font
         * @var m_font
         ****************************************************************************************************/
        sf::Font m_font;

    /****************************************************************************************************
     * @publicsection
     ****************************************************************************************************/
    public:

        /****************************************************************************************************
         * @function Score(shared_ptr<logic::Player_L> player);
         * @brief Is een constructor die een player zal toekennen en zal de font inladen voor de score weer te geven.
         * @param player: shared_ptr<logic::Player_L> is de speler die wordt toegekent.
         ****************************************************************************************************/
        Score(shared_ptr<logic::Player_L> player);

        /****************************************************************************************************
         * @function void update() override
         * @brief Zal de update functie overschrijven zodat de score altijd geupdate worden want hier moet niet
         * een afbeelding getoont worden maar de text van de score wordt wel geupdate.
         ****************************************************************************************************/
        void update() override;

        /****************************************************************************************************
         * @function void draw()
         * @brief Zal de score weergeven op de window.
         ****************************************************************************************************/
        void draw();

        /****************************************************************************************************
         * @function ~Score()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Score() override;


    };
}


#endif //DOODLE_JUMP_SCORE_H
