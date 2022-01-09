#include "Bonus.h"

namespace representation {

Bonus::Bonus() = default;

Bonus::Bonus(shared_ptr<logic::Bonus_L> bonus, string& image) : EntityView(bonus->getWidth(), bonus->getHeight(), image)
{
        ControllingPointers::control(bonus, "Bonus", "Bonus(shared_ptr<logic::Bonus_L> bonus, string& image)");
        setEntityModel(move(bonus));
}

Spring::Spring(shared_ptr<logic::Bonus_L> bonus, string image) : Bonus(move(bonus), image) {}

Rocket::Rocket(shared_ptr<logic::Bonus_L> bonus, string image) : Bonus(move(bonus), image) {}

Bonus::~Bonus() = default;

Spring::~Spring() = default;

Rocket::~Rocket() = default;
} // namespace representation