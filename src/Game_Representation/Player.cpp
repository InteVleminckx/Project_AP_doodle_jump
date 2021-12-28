#include "Player.h"

namespace representation {

    Player::Player()= default;

    Player::Player(shared_ptr<logic::Player_L> player, string image) : EntityView(player->getWidth(), player->getHeight(), image)
    {
        setEntityModel(move(player));
    }

    Player::~Player() {
        cout << "delete Player observer" << endl;
    }
}