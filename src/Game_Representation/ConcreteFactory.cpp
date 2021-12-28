#include "ConcreteFactory.h"

#include <memory>

representation::ConcreteFactory::ConcreteFactory() = default;

void representation::ConcreteFactory::createPlayer(const shared_ptr<logic::Player_L> &player) {

    unique_ptr<logic::Observer> player_O = move(make_unique<representation::Player>(player, "../Sprites/Doodle_player2.png"));
    player->addObserver(move(player_O));
}

void representation::ConcreteFactory::createBG_Tile(const shared_ptr<logic::BG_Tile_L> &BG_tile) {

    unique_ptr<logic::Observer> BG_tile_O = move(make_unique<representation::BG_Tile>(BG_tile, "../Sprites/BG_tile.png"));
    BG_tile->addObserver(move(BG_tile_O));
}

void representation::ConcreteFactory::createPlatform(const shared_ptr<logic::Platform_L> &platform, PlatformType type) {

    unique_ptr<logic::Observer> platform_O;

    switch (type) {
        case Static_:
            platform_O = move(make_unique<representation::Platform_static>(platform, "../Sprites/Static_platforms.png"));
            break;
        case Horizontal_:
            platform_O = move(make_unique<representation::Platform_horizontal>(platform, "../Sprites/Horizontal_platforms.png"));
            break;
        case Vertical_:
            platform_O = move(make_unique<representation::Platform_vertical>(platform, "../Sprites/Vertical_platforms.png"));

            break;
        case Temporary_:
            platform_O = move(make_unique<representation::Platform_temporary>(platform, "../Sprites/Temporary_platforms.png"));

    }

    platform->addObserver(move(platform_O));

}

void representation::ConcreteFactory::createBonus(const shared_ptr<logic::Bonus_L> &bonus, BonusType type) {

    unique_ptr<logic::Observer> bonus_O;

    switch (type) {
        case Spring_:
            bonus_O = move(make_unique<representation::Spring>(bonus, "../Sprites/Spring.png"));
            break;
        case Rocket_:
            bonus_O = move(make_unique<representation::Rocket>(bonus, "../Sprites/Rocket.png"));
    }

    bonus->addObserver(move(bonus_O));
}

void representation::ConcreteFactory::createScore(const shared_ptr<logic::Player_L> &subject) {
    unique_ptr<logic::Observer> score_o = move(make_unique<representation::Score>(subject));
    subject->addObserver(move(score_o));
}

representation::ConcreteFactory::~ConcreteFactory() {cout << "delete concreteFactory << endl";}
