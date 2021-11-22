//
// Created by inte on 11/22/21.
//

#include "Exceptions.h"

InputException::InputException() {

}

const char *InputException::what() const noexcept {
    return "Can't open the input file with path: ";
}
