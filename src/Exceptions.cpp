//
// Created by inte on 11/22/21.
//

#include "Exceptions.h"


const char *InputImageException::what() const noexcept {
    return "Can't open the input image with path: ";
}

const char *InputFontException::what() const noexcept {
    return "Can't open the input font with path: ";
}
