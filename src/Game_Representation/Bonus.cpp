#include "Bonus.h"

namespace representation {

    Bonus::Bonus() = default;

    Spring::Spring() = default;

    Rocket::Rocket() = default;

    Bonus::Bonus(shared_ptr<logic::Bonus_L> bonus, string& image): EntityView(bonus->getWidth(), bonus->getHeight(), image)
    {
        ControllingPointers::control(bonus, "Bonus", "Bonus(shared_ptr<logic::Bonus_L> bonus, string& image)");
        setEntityModel(move(bonus));
    }

    Bonus::~Bonus() {}

    Spring::Spring(shared_ptr<logic::Bonus_L> bonus, string image) : Bonus(move(bonus), image) {}

    Spring::~Spring() {}

    Rocket::Rocket(shared_ptr<logic::Bonus_L> bonus, string image) : Bonus(move(bonus), image){}

    Rocket::~Rocket() {}
}