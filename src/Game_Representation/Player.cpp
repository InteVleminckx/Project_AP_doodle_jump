#include "Player.h"

namespace representation {

Player::Player() = default;

Player::Player(shared_ptr<logic::Player_L> player, const string& image)
    : EntityView(player->getWidth(), player->getHeight(), image)
{
        ControllingPointers::control(player, "Player",
                                     "Player(shared_ptr<logic::Player_L> player, const string& image)");
        setEntityModel(move(player));
}

Player::~Player() = default;
} // namespace representation