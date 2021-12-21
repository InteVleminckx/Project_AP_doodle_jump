#include "ConcreteFactory.h"

#include <memory>

representation::ConcreteFactory::ConcreteFactory() = default;

void representation::ConcreteFactory::createPlayer(shared_ptr<logic::Player_L> &player) {
    player->addObserver(shared_ptr<logic::Observer> (
            new representation::Player(player, "../Sprites/Doodle_player2.png")));
}

void representation::ConcreteFactory::createBG_Tile(shared_ptr<logic::BG_Tile_L> &BG_tile) {
    BG_tile->addObserver(shared_ptr<logic::Observer> (
            new representation::BG_Tile(BG_tile, "../Sprites/BG_tile.png")));
}

void representation::ConcreteFactory::createPlatform(shared_ptr<logic::Platform_L> &platform, PlatformType type) {

    switch (type) {
        case Static_:
            platform->addObserver(shared_ptr<logic::Observer> (
                    new representation::Platform_static(platform, "../Sprites/Static_platforms.png")));
            break;
        case Horizontal_:
            platform->addObserver(shared_ptr<logic::Observer> (
                    new representation::Platform_horizontal(platform, "../Sprites/Horizontal_platforms.png")));
            break;
        case Vertical_:
            platform->addObserver(shared_ptr<logic::Observer> (
                    new representation::Platform_vertical(platform, "../Sprites/Vertical_platforms.png")));
            break;
        case Temporary_:
            platform->addObserver(shared_ptr<logic::Observer> (
                    new representation::Platform_temporary(platform, "../Sprites/Temporary_platforms.png")));
    }
}

void representation::ConcreteFactory::createBonus(shared_ptr<logic::Bonus_L> &bonus, BonusType type) {
    switch (type) {
        case Spring_:
            bonus->addObserver(shared_ptr<logic::Observer> (
                    new representation::Spring(bonus, "../Sprites/Spring.png")));
            break;
        case Rocket_:
            bonus->addObserver(shared_ptr<logic::Observer> (
                    new representation::Rocket(bonus, "../Sprites/Rocket.png")));
    }
}

void representation::ConcreteFactory::createScore(shared_ptr<logic::Player_L> &subject, shared_ptr<logic::Score>& score) {
    score = std::make_shared<logic::Score>(subject);
    subject->addObserver(score);
}
