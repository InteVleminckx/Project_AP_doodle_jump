#include "ConcreteFactory.h"

#include <memory>

representation::ConcreteFactory::ConcreteFactory() = default;

void representation::ConcreteFactory::createPlayer(shared_ptr<logic::Player_L> &player) {

    shared_ptr<logic::Observer> player_O;
    player_O = move(make_shared<representation::Player>(player, "../Sprites/Doodle_player2.png"));
    player->addObserver(player_O);
}

void representation::ConcreteFactory::createBG_Tile(shared_ptr<logic::BG_Tile_L> &BG_tile) {

    shared_ptr<logic::Observer> BG_tile_O;
    BG_tile_O = move(make_shared<representation::BG_Tile>(BG_tile, "../Sprites/BG_tile.png"));
    BG_tile->addObserver(BG_tile_O);
}

void representation::ConcreteFactory::createPlatform(shared_ptr<logic::Platform_L> &platform, PlatformType type) {

    shared_ptr<logic::Observer> platform_O;

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

    platform->addObserver(platform_O);

}

void representation::ConcreteFactory::createBonus(shared_ptr<logic::Bonus_L> &bonus, BonusType type) {

    shared_ptr<logic::Observer> bonus_O;

    switch (type) {
        case Spring_:
            bonus_O = move(make_shared<representation::Spring>(bonus, "../Sprites/Spring.png"));
            break;
        case Rocket_:
            bonus_O = move(make_shared<representation::Rocket>(bonus, "../Sprites/Rocket.png"));
    }

    bonus->addObserver(bonus_O);
}

void representation::ConcreteFactory::createScore(shared_ptr<logic::Player_L> &subject, shared_ptr<logic::Score>& score) {

    score->setPlayer(subject);
    subject->addObserver(score);

}

representation::ConcreteFactory::~ConcreteFactory() {cout << "delete concreteFactory << endl";}
