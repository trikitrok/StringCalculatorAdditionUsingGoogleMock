#pragma once

#include <string>

class StringCalculator
{
public:
  StringCalculator();
  virtual ~StringCalculator();

  int add(const std::string & numbersSequence);
};

