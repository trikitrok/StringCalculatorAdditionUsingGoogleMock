#include "StringCalculator.h"

#include <cstdlib> 

StringCalculator::StringCalculator() {}


StringCalculator::~StringCalculator() {}

int StringCalculator::add(const std::string & numbersSequence) {
  if (numbersSequence.empty())
    return 0;

  return atoi(numbersSequence.c_str());
}
