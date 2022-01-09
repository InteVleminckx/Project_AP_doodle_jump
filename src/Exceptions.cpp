#include "Exceptions.h"

const char* InputImageException::what() const noexcept { return "Can't open the input image with path: "; }

const char* InputFontException::what() const noexcept { return "Can't open the input font with path: "; }

const char* InputSaveFileException::what() const noexcept { return "Can't open the saved file with path: "; }

nullptrException::nullptrException(const string className, const string functionName)
    : m_className(className), m_functionName(functionName)
{
}

string nullptrException::what_() const
{
        return "Pointer dat je wil gebruiken is een nullptr in de class: " + m_className +
               " met de function: " + m_functionName;
}
