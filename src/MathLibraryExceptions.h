//
// Created by Jaromir Otevrel
// Edited by Jan Brudny
//

#ifndef KARCULATQR_MATHLIBRARY_EXC_H
#define KARCULATQR_MATHLIBRARY_EXC_H
#include <iostream>
using namespace std;

enum class MathLibraryExceptionType {
  NoNumbersToCalculate,
  NoNumberToCalculate,
  DivisionByZero,   
  NegativeFactorial, 
  NegativeRoot,
  InvalidInput,
  NoCurrentValue,
  NoPreviousResult
};

class MathLibraryException : public std::exception {
private:
  std::string message_;
  enum MathLibraryExceptionType type_;

public:
  MathLibraryException(const std::string& message, enum MathLibraryExceptionType type);
  virtual const char* what() const noexcept override;

}; 

#endif //KARCULATQR_MATHLIBRARY_EXC_H
