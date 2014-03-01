#pragma once

#include <string>
#include <exception>

class NegativeNumbersException : public std::runtime_error
{
public:
  NegativeNumbersException(const std::string & negativeNumbersList);
  virtual ~NegativeNumbersException() throw();
};

