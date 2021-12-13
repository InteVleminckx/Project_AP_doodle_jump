#include "ConcreteFactory.h"

void Representation::ConcreteFactory::createPlayer(shared_ptr<logic::Player_L> &player) {
    player->addObserver(shared_ptr<logic::Observer> (
            new representation::Player(player, "../Sprites/Doodle_player2.png")));
}

void Representation::ConcreteFactory::createBG_Tile(shared_ptr<logic::BG_Tile_L> &BG_tile) {
    BG_tile->addObserver(shared_ptr<logic::Observer> (
            new representation::BG_Tile(BG_tile, "../Sprites/BG_tile.png")));
}

void Representation::ConcreteFactory::createPlatform(shared_ptr<logic::Platform_L> &platform, _Platform type) {

    switch (type) {
        case Static:
            platform->addObserver(shared_ptr<logic::Observer> (
                    new representation::Platform_static(platform, "../Sprites/Static_platforms.png")));
            break;
        case Horizontal:
            platform->addObserver(shared_ptr<logic::Observer> (
                    new representation::Platform_horizontal(platform, "../Sprites/Horizontal_platforms.png")));
            break;
        case Vertical:
            platform->addObserver(shared_ptr<logic::Observer> (
                    new representation::Platform_vertical(platform, "../Sprites/Vertical_platforms.png")));
            break;
        case Temporary:
            platform->addObserver(shared_ptr<logic::Observer> (
                    new representation::Platform_temporary(platform, "../Sprites/Temporary_platforms.png")));
    }
}

void Representation::ConcreteFactory::createBonus(shared_ptr<logic::Bonus_L> &bonus, _Bonus type) {
    switch (type) {
        case Spring:
            bonus->addObserver(shared_ptr<logic::Observer> (
                    new representation::Spring(bonus, "../Sprites/Spring.png")));
            break;
        case Rocket:
            bonus->addObserver(shared_ptr<logic::Observer> (
                    new representation::Rocket(bonus, "../Sprites/Rocket.png")));
    }
}
