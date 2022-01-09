#include "Score_L.h"
#include "Random.h"

namespace logic {

Score_L::Score_L(shared_ptr<Player_L> player)
{
        ControllingPointers::control(player, "Score_L", "Score_L(shared_ptr<Player_L> player) ");

        m_negativesPoints = 0;
        m_positivesPoints = 0;
        m_player = move(player);
};

int Score_L::getScore() { return m_score; }

void Score_L::setScore(float score) { m_score = Camera::Instance()->reproduceScore(score); }

shared_ptr<Player_L> Score_L::getPlayer() { return m_player; }

void Score_L::update() { updateScore(); }

void Score_L::updateScore()
{
        // Veranderd de moeilijkheidsgraad als dit nodig is.
        logic::Random::Instance()->refreshDifficulty(m_score);
        if (Camera::Instance()->reproduceScore(getPlayer()->getY()) > getScore())
                setScore(getPlayer()->getY());
}

void Score_L::addNegativePoints(int points) { m_negativesPoints += points; }

void Score_L::addPositivesPoints(int points) { m_positivesPoints += points; }

int Score_L::getRecalculatedScore()
{
        int result = m_score - m_negativesPoints + m_positivesPoints;
        if (result < 0)
                return 0;
        else
                return result;
}

Score_L::~Score_L() = default;
} // namespace logic