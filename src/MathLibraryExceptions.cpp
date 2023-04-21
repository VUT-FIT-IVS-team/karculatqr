/**
* @file MathLibraryExceptions.cpp
* @brief MathLibraryExceptions class implementation
* @date 21/04/2023
* @author 🦆 Team 
* @version 1.0
*/

#include "MathLibraryExceptions.h"

MathLibraryException::MathLibraryException(const std::string& message, enum MathLibraryExceptionType type) {
    this->message_ = message;
    this->type_ = type;
}
const char* MathLibraryException::what() const noexcept {
    return this->message_.c_str();
}