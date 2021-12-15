//
// Created by inte_vleminckx on 15.12.21.
//

#ifndef DOODLE_JUMP_SCORE_H
#define DOODLE_JUMP_SCORE_H
#include "Observer.h"
#include "Player.h"


namespace logic {
    class Score : public Observer{

        float m_score{};

        shared_ptr<Player_L> m_player;

        Score();

    public:

        Score(shared_ptr<Player_L>& player);

        void update() override;

        float getScore();

    };
}


#endif //DOODLE_JUMP_SCORE_H
