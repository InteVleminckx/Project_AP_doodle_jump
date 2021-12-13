#include "Bonus.h"

namespace representation {

    Bonus::Bonus() = default;

    Spring::Spring() = default;

    Rocket::Rocket() = default;

    Bonus::Bonus(shared_ptr<logic::Bonus_L> &bonus, string& image): EntityView(bonus->getWidth(), bonus->getHeight(), image)
    {
        setEntityModel(bonus);
    }

    Spring::Spring(shared_ptr<logic::Bonus_L> &bonus, string image) : Bonus(bonus, image) {}

    Rocket::Rocket(shared_ptr<logic::Bonus_L> &bonus, string image) : Bonus(bonus, image){}
}