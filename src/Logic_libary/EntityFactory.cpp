#include "EntityFactory.h"

namespace logic {

    EntityFactory::EntityFactory() = default;

    EntityFactory::~EntityFactory() {
        cout << "delete entityfactory"  << endl;
    }
}
