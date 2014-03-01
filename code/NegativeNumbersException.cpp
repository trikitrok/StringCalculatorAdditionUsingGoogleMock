#include "NegativeNumbersException.h"

NegativeNumbersException::NegativeNumbersException(
  const std::string & negativeNumbersList)
: std::runtime_error("Negative numbers not allowed " + negativeNumbersList)
{}

NegativeNumbersException::~NegativeNumbersException() 
{}
