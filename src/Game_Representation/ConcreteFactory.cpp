#include "ConcreteFactory.h"

void Representation::ConcreteFactory::createPlayer(shared_ptr<logic::Subject> &subject) {
    subject->addObserver(shared_ptr<logic::Observer> (new representation::Player(subject)));
}

void Representation::ConcreteFactory::createBG_Tile(shared_ptr<logic::Subject> &subject) {

}

void Representation::ConcreteFactory::createPlatform(shared_ptr<logic::Subject> &subject, _Platform type) {

    switch (type) {
        case Static:
            subject->addObserver(shared_ptr<logic::Observer> (new representation::Platform_static(subject)));
            break;
        case Horizontal:
            subject->addObserver(shared_ptr<logic::Observer> (new representation::Platform_horizontal(subject)));
            break;
        case Vertical:
            subject->addObserver(shared_ptr<logic::Observer> (new representation::Platform_vertical(subject)));
            break;
        case Temporary:
            subject->addObserver(shared_ptr<logic::Observer> (new representation::Platform_temporary(subject)));
    }
}

void Representation::ConcreteFactory::createBonus(shared_ptr<logic::Subject> &subject, _Bonus type) {

}
