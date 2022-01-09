/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum 09/01/2022
 * @Class Exceptions
 * @BaseClass exception
 * @SubClasses none
 * @Namespace none
 * @brief Geeft gerichte exceptions weer.
 ****************************************************************************************************/


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

class InputSaveFileException : exception{
public:

    InputSaveFileException() = default;
    const char * what() const noexcept override;
};

class nullptrException : exception{
    string m_className;
    string m_functionName;
public:

    nullptrException(string className, string functionName);
    string what_() const;
};


#endif //DOODLE_JUMP_EXCEPTIONS_H
