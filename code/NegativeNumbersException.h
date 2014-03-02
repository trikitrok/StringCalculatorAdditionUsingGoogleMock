#pragma once

#include <string>
#include <exception>

class NegativeNumbersException : public std::runtime_error
{
public:
  NegativeNumbersException(const std::string & negativeNumbersList) 
    : std::runtime_error("Negative numbers not allowed " + negativeNumbersList) 
  {}

  virtual ~NegativeNumbersException() throw() 
  {};
};

