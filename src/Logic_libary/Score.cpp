#include "Score.h"

namespace logic {


    Score::Score(shared_ptr<Player_L> &player) : m_player(player){}

    void Score::update() {
        if (m_player->getY() > m_score) m_score = m_player->getY();
    }

    float Score::getScore() {
        return m_score;
    }
}