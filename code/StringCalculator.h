#pragma once

#include <string>
#include <vector>

class StringCalculator
{
public:
  StringCalculator();
  virtual ~StringCalculator();

  int add(const std::string & numbersSequence);

private:
  std::vector<int> extractNumbers(const std::string & numbersSequence);
};

