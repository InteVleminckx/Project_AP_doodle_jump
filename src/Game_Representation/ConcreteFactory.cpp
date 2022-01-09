#include "ConcreteFactory.h"

#include <memory>

namespace representation {

ConcreteFactory::ConcreteFactory() = default;

void ConcreteFactory::createPlayer(const shared_ptr<logic::Player_L>& player)
{
        ControllingPointers::control(player, "ConcreteFactory",
                                     "createPlayer(const shared_ptr<logic::Player_L> &player)");

        // Maken een representation player aan.
        shared_ptr<Player> player_O = move(make_shared<Player>(player, "../Sprites/Doodle_player2.png"));
        player->addObserver(player_O);
        m_player = move(player_O);
}

void ConcreteFactory::createBG_Tile(const shared_ptr<logic::BG_Tile_L>& BG_tile)
{
        ControllingPointers::control(BG_tile, "ConcreteFactory",
                                     "createBG_Tile(const shared_ptr<logic::BG_Tile_L> &player)");

        // Maken een representation Background tile aan
        shared_ptr<BG_Tile> BG_tile_O = move(make_shared<BG_Tile>(BG_tile, "../Sprites/BG_tile.png"));
        BG_tile->addObserver(BG_tile_O);
        m_BG_Tiles.push_back(move(BG_tile_O));
}

void ConcreteFactory::createPlatform(const shared_ptr<logic::Platform_L>& platform, PlatformType type)
{
        ControllingPointers::control(platform, "ConcreteFactory",
                                     "createPlatform(const shared_ptr<logic::Platform_L> &player)");

        // Maken een representation platform aan, deze hangt af van het platform type dat wordt meegeven.
        shared_ptr<Platform> platform_O;

        switch (type) {
        case Static_:
                platform_O = move(make_shared<Platform_static>(platform, "../Sprites/Static_platforms.png"));
                break;
        case Horizontal_:
                platform_O = move(make_shared<Platform_horizontal>(platform, "../Sprites/Horizontal_platforms.png"));
                break;
        case Vertical_:
                platform_O = move(make_shared<Platform_vertical>(platform, "../Sprites/Vertical_platforms.png"));

                break;
        case Temporary_:
                platform_O = move(make_shared<Platform_temporary>(platform, "../Sprites/Temporary_platforms.png"));
        }
        platform->addObserver(platform_O);
        m_platforms.push_back(move(platform_O));
}

void ConcreteFactory::createBonus(const shared_ptr<logic::Bonus_L>& bonus, BonusType type)
{
        ControllingPointers::control(bonus, "ConcreteFactory", "createBonus(const shared_ptr<logic::Bonus_L> &player)");

        // Maken een representation bonus aan, deze hangt af van het bonustype dat wordt meegeven.
        shared_ptr<Bonus> bonus_O;

        switch (type) {
        case Spring_:
                bonus_O = move(make_shared<Spring>(bonus, "../Sprites/Spring.png"));
                break;
        case Rocket_:
                bonus_O = move(make_shared<Rocket>(bonus, "../Sprites/Rocket.png"));
        }

        bonus->addObserver(bonus_O);
        m_bonussen.push_back(move(bonus_O));
}

void ConcreteFactory::createScore(const shared_ptr<logic::Player_L>& player, shared_ptr<logic::Score_L>& score)
{
        ControllingPointers::control(player, "ConcreteFactory",
                                     "createScore(const shared_ptr<logic::Player_L> &player)");

        // Maken een score aan dat dit als observer.
        shared_ptr<Score> score_o = move(make_shared<Score>(player));
        score = score_o;
        player->addObserver(score_o);
        m_score = move(score_o);
}

shared_ptr<Player>& ConcreteFactory::getPlayer() { return m_player; }

shared_ptr<Score>& ConcreteFactory::getScore() { return m_score; }

vector<shared_ptr<Platform>>& ConcreteFactory::getPlatforms() { return m_platforms; }

vector<shared_ptr<BG_Tile>>& ConcreteFactory::getBG_Tiles() { return m_BG_Tiles; }

vector<shared_ptr<Bonus>>& ConcreteFactory::getBonussen() { return m_bonussen; }

ConcreteFactory::~ConcreteFactory() = default;
} // namespace representation
