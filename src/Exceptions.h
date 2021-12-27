//
// Created by inte on 11/22/21.
//

#ifndef DOODLE_JUMP_EXCEPTIONS_H
#define DOODLE_JUMP_EXCEPTIONS_H

#include <iostream>
#include <exception>

using namespace std;

class InputImageException : exception{
public:

    InputImageException() = default;
    const char * what() const noexcept override;
};

class InputFontException : exception{
public:

    InputFontException() = default;
    const char * what() const noexcept override;
};


#endif //DOODLE_JUMP_EXCEPTIONS_H
